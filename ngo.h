#ifndef NGO_H
#define NGO_H

#include <QDialog>
#include <QTcpSocket>
#include <QStandardItemModel>

namespace Ui {
class NGO;
}

class NGO : public QDialog
{
    Q_OBJECT

public:
    explicit NGO(QWidget *parent = nullptr);
    ~NGO();

private slots:
    void sendMessage();
    void readMessage();
    void onConnected();
    void storeMessageInDatabase(const QString &message);
    void loadAllMessages();
    void on_connectbutton2_clicked();

    void on_messageListView_clicked(const QModelIndex &index);

private:
    Ui::NGO *ui;
    QTcpSocket *tcpSocket;
    QStandardItemModel *model;
    bool deleteMessageFromDatabase(int messageId);
};

#endif // NGO_H
