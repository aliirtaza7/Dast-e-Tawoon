#ifndef NEEDYPERSON_H
#define NEEDYPERSON_H

#include <QDialog>
#include <QTcpSocket>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class NeedyPerson;
}

class NeedyPerson : public QDialog
{
    Q_OBJECT

public:
    explicit NeedyPerson(QWidget *parent = nullptr);
    ~NeedyPerson();
    void getPhoneNo(const QString &username);
    void populateNgoList();

private slots:
    void on_sendMessage_clicked();
    void on_connectbutton_clicked();

private:
    Ui::NeedyPerson *ui;
    QTcpSocket *tcpSocket;
    QStandardItemModel *model;
    QString phoneNo;
};

#endif // NEEDYPERSON_H
