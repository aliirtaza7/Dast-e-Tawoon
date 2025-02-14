#include "needyperson.h"
#include "np_log_in.h"
#include "ui_needyperson.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

NeedyPerson::NeedyPerson(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NeedyPerson)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->listView->setModel(model);
    populateNgoList();
    tcpSocket = new QTcpSocket(this);
}

NeedyPerson::~NeedyPerson()
{
    delete ui;
}

void NeedyPerson::getPhoneNo(const QString &username) {
    QString queryString = "SELECT PhoneNo FROM needyPerson WHERE Needyusername = :username";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":username", username);

    if (query.exec()) {
        if (query.next()) {
            phoneNo = query.value("PhoneNo").toString();
        } else {
            QMessageBox msgBox;
            msgBox.setStyleSheet("QMessageBox {"
                                 "background-color: black;"
                                 "color: Red;"
                                 "border: none;"
                                 "font: bold 14px;"
                                 "}");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("No Record Found");
            msgBox.setText("No matching username found.");
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Query Error");
        msgBox.setText(query.lastError().text());
        msgBox.exec();
    }
}

void NeedyPerson::populateNgoList() {
    model->clear();
    QString queryString = "SELECT NgoName FROM ngo";
    QSqlQuery query;
    if (query.exec(queryString)) {
        while (query.next()) {
            QString itemText = query.value(0).toString();
            QStandardItem *item = new QStandardItem(itemText);
            model->appendRow(item);
        }
    } else {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Query Error");
        msgBox.setText(query.lastError().text());
        msgBox.exec();
    }
}

void NeedyPerson::on_sendMessage_clicked() {
    getPhoneNo(username);
    QString message = ui->messageTextEdit->toPlainText();
    QString hospital = ui->hospitalname->text();
    QString city = ui->cityname->text();
    if ((!message.isEmpty()) && (!city.isEmpty()) && (!hospital.isEmpty())) {
        if (tcpSocket && tcpSocket->state() == QAbstractSocket::ConnectedState) {
            tcpSocket->write((username + " :\n" + message + "\nHospital Name  : " +
                              hospital + " " + city + "\nPHONE NO : " + phoneNo + "\n   ").toUtf8());

            QMessageBox msgBox;
            msgBox.setStyleSheet("QMessageBox {"
                                 "background-color: black;"
                                 "color: Red;"
                                 "border: none;"
                                 "font: bold 14px;"
                                 "}");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Message Sent");
            msgBox.setText("Your message has been sent to the server.");
            msgBox.exec();

            ui->messageTextEdit->clear();
        } else {
            QMessageBox msgBox;
            msgBox.setStyleSheet("QMessageBox {"
                                 "background-color: black;"
                                 "color: black;"
                                 "border: none;"
                                 "font: bold 14px;"
                                 "}");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Connection Error");
            msgBox.setText("Not connected to the server.");
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: black;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Empty Message");
        msgBox.setText("Please enter a message before sending.");
        msgBox.exec();
    }
}

void NeedyPerson::on_connectbutton_clicked() {
    QString ipAddress = ui->ipaddress->text();
    if (ipAddress.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: black;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Invalid Input");
        msgBox.setText("Please enter an IP address.");
        msgBox.exec();
        return;
    }
    tcpSocket->connectToHost(ipAddress, 1234);
    if (tcpSocket->waitForConnected(5000)) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: black;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Connected");
        msgBox.setText("Successfully connected to the server.");
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: black;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Connection Error");
        msgBox.setText("Failed to connect to the server.");
        msgBox.exec();
    }
}
