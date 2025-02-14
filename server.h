#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    void storeMessageInDatabase(const QString &message, const QString &ngoName);
    void sendUnsentMessages(QTcpSocket* ngoSocket);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void readMessage();
    void clientDisconnected();

private:
    QList<QTcpSocket *> clients;
    QString getNgoName(QTcpSocket* socket); // Helper function to get NGO name
};

#endif // SERVER_H
