#include "server.h"
#include <QNetworkInterface>
#include <QCoreApplication>
#include <QDebug>
#include <QHostAddress>
#include <QSqlQuery>
#include <QSqlError>

Server::Server(QObject *parent)
    : QTcpServer(parent) {
    QHostAddress address;
    bool found = false;

    // Get the first non-localhost address (IPv4)
    foreach (const QNetworkInterface &interface, QNetworkInterface::allInterfaces()) {
        foreach (const QNetworkAddressEntry &entry, interface.addressEntries()) {
            if (entry.ip().toString() != "127.0.0.1" && entry.ip().toString().startsWith("10")) {
                address = entry.ip();
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        qCritical() << "No suitable network address found!";
        return;
    }

    qDebug() << "Server started on IP address:" << address.toString();

    if (!this->listen(address, 1234)) {
        qCritical() << "Server could not start!";
        return;
    }

    qDebug() << "Server is listening on port" << this->serverPort();
}

void Server::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    clients.append(socket);

    connect(socket, &QTcpSocket::readyRead, this, &Server::readMessage);
    connect(socket, &QTcpSocket::disconnected, this, &Server::clientDisconnected);

    qDebug() << "New client connected";

    // Once an NGO connects, send them any unsent messages
    sendUnsentMessages(socket);
}

void Server::readMessage() {
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket) return;

    QByteArray data = senderSocket->readAll();
    QString message = QString::fromUtf8(data);

    // Check if the NGO is connected. If not, store the message in the database.
    QString ngoName = getNgoName(senderSocket);
    if (ngoName.isEmpty()) {
        // Store message in the database for later delivery
        storeMessageInDatabase(message, ngoName);
    } else {
        // Forward the message to all other clients
        for (QTcpSocket *client : clients) {
            if (client != senderSocket) {
                client->write(data);
                client->flush();
            }
        }
    }

    qDebug() << "Message forwarded to all NGOs:" << message;
}

void Server::storeMessageInDatabase(const QString& message, const QString& ngoName) {
    QSqlQuery query;
    query.prepare("INSERT INTO unsent_messages (message, ngo_name) VALUES (:message, :ngo_name)");
    query.bindValue(":message", message);
    query.bindValue(":ngo_name", ngoName);

    if (!query.exec()) {
        qCritical() << "Failed to store unsent message:" << query.lastError();
    }
}

void Server::sendUnsentMessages(QTcpSocket* ngoSocket) {
    QString ngoName = getNgoName(ngoSocket);
    if (ngoName.isEmpty()) return;

    QString queryStr = "SELECT * FROM unsent_messages WHERE ngo_name = :ngo_name AND is_sent = FALSE";
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":ngo_name", ngoName);

    if (query.exec()) {
        while (query.next()) {
            QString message = query.value("message").toString();
            QString needyUsername = query.value("needy_username").toString();
            QString phoneNo = query.value("phone_no").toString();

            // Forward the message to the NGO
            ngoSocket->write(QString("%1 : %2").arg(needyUsername).arg(message).toUtf8());

            // Mark the message as sent
            QString updateQuery = "UPDATE unsent_messages SET is_sent = TRUE WHERE id = :id";
            QSqlQuery update;
            update.prepare(updateQuery);
            update.bindValue(":id", query.value("id").toInt());
            update.exec();
        }
    } else {
        qCritical() << "Failed to fetch unsent messages:" << query.lastError();
    }
}

void Server::clientDisconnected() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    clients.removeAll(socket);
    socket->deleteLater();

    qDebug() << "Client disconnected";
}

QString Server::getNgoName(QTcpSocket* socket) {
    // Implement this function to retrieve the NGO name based on the socket (session)
    return "ExampleNGO";  // Placeholder, implement logic to get actual NGO name
}

