#include "ngo.h"
#include "ui_ngo.h"
#include <QMessageBox>
#include <QByteArray>
#include <QTextOption>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

NGO::NGO(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NGO)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->messageListView->setModel(model);
    ui->messageListView->setWordWrap(true);
    ui->messageListView->setResizeMode(QListView::Adjust);

    tcpSocket = new QTcpSocket(this);

    connect(ui->sendMessageButton, &QPushButton::clicked, this, &NGO::sendMessage);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &NGO::readMessage);
    connect(tcpSocket, &QTcpSocket::connected, this, &NGO::onConnected);

    // Show all messages in the list view when the app starts
    loadAllMessages();
}

NGO::~NGO()
{
    delete ui;
}

void NGO::sendMessage() {
    QString message = ui->messageTextEdit->toPlainText();

    if (!message.isEmpty()) {
        tcpSocket->write(message.toUtf8());

        QStandardItem *item = new QStandardItem("Sent: " + message);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
        model->appendRow(item);

        ui->messageTextEdit->clear();
    } else {
        // Apply custom QSS style to the QMessageBox
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Empty Message");
        msgBox.setText("Please enter a message before sending.");
        msgBox.exec();
    }
}

void NGO::readMessage() {
    QByteArray data = tcpSocket->readAll();
    QString message = QString::fromUtf8(data);

    // Insert the received message into the receive_messages table
    storeMessageInDatabase(message);

    // Display the received message in the message list
    QStandardItem *item = new QStandardItem("Received: " + message);
    item->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
    model->appendRow(item);

    ui->messageTextEdit->setPlainText(message);
}

void NGO::onConnected() {
    // Apply custom QSS style to the QMessageBox
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {"
                         "background-color: black;"
                         "color: Red;"
                         "border: none;"
                         "font: bold 14px;"
                         "}");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Connected");
    msgBox.setText("Successfully connected to the server.");
    msgBox.exec();
}

void NGO::on_connectbutton2_clicked() {
    QString ipAddress = ui->ipaddressngo->text();
    if (ipAddress.isEmpty()) {
        // Apply custom QSS style to the QMessageBox
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Invalid Input");
        msgBox.setText("Please enter an IP address.");
        msgBox.exec();
        return;
    }

    tcpSocket->connectToHost(QHostAddress(ipAddress), 1234);
    if (!tcpSocket->waitForConnected(5000)) {
        // Apply custom QSS style to the QMessageBox
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Connection Error");
        msgBox.setText("Failed to connect to the server.");
        msgBox.exec();
    }
}

// Function to store a received message in the receive_messages table
void NGO::storeMessageInDatabase(const QString &message) {
    QSqlQuery query;
    query.prepare("INSERT INTO receive_messages (message) VALUES (:message)");
    query.bindValue(":message", message);

    if (!query.exec()) {
        // Apply custom QSS style to the QMessageBox
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to insert message into database: " + query.lastError().text());
        msgBox.exec();
    }
}

// Function to load all messages from the receive_messages table and display them
void NGO::loadAllMessages() {
    QSqlQuery query("SELECT id, message FROM receive_messages");
    if (query.exec()) {
        while (query.next()) {
            int id = query.value("id").toInt();  // Get the id from the query
            QString message = query.value("message").toString();

            // Display the message in the list view
            QStandardItem *item = new QStandardItem("Received: \n" + message);
            item->setData(id, Qt::UserRole);  // Store the id in the item's data
            item->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
            model->appendRow(item);
        }
    } else {
        // Apply custom QSS style to the QMessageBox
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to load messages from the database: " + query.lastError().text());
        msgBox.exec();
    }
}

void NGO::on_messageListView_clicked(const QModelIndex &index)
{
    // Get the clicked item
    QStandardItem *item = model->itemFromIndex(index);

    // Retrieve the ID associated with the message
    int messageId = item->data(Qt::UserRole).toInt();

    // Show a confirmation dialog to delete the message
    QMessageBox::StandardButton reply;

    // Create the delete confirmation QMessageBox
    QMessageBox msgBoxDEL;
    msgBoxDEL.setStyleSheet("QMessageBox {"
                            "background-color: black;"
                            "color: Red;"
                            "border: none;"
                            "font: bold 14px;"
                            "}");
    reply = msgBoxDEL.question(this, "Delete Message", "Are you sure you want to delete this message?",
                               QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Delete the message from the database using the ID
        if (deleteMessageFromDatabase(messageId)) {
            // Remove the item from the list view
            model->removeRow(index.row());
        } else {
            // Apply custom QSS style to the QMessageBox for error
            QMessageBox msgBoxError;
            msgBoxError.setStyleSheet("QMessageBox {"
                                      "background-color: black;"
                                      "color: Red;"
                                      "border: none;"
                                      "font: bold 14px;"
                                      "}");
            msgBoxError.setIcon(QMessageBox::Critical);
            msgBoxError.setWindowTitle("Database Error");
            msgBoxError.setText("Failed to delete the message from the database.");
            msgBoxError.exec();
        }
    }
}

bool NGO::deleteMessageFromDatabase(int messageId) {
    QSqlQuery query;
    query.prepare("DELETE FROM receive_messages WHERE id = :id");
    query.bindValue(":id", messageId);
    return query.exec();
}
