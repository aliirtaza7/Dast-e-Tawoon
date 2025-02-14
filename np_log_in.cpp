#include "np_log_in.h"
#include "ui_np_log_in.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <databasemanagement.h>

Np_Log_in::Np_Log_in(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Np_Log_in)
{
    ui->setupUi(this);
    dbmanagement.connectToDatabase();
}

Np_Log_in::~Np_Log_in()
{
    delete ui;
}

bool Np_Log_in::verifyNeedyLogin(const QString &username, const QString &nppassword)
{
    // Prepare your query to select from the 'needyperson' table
    QSqlQuery query;
    // Execute the query
    if (query.exec("SELECT * FROM needyperson")) {
        // Loop through all rows in the result set
        while (query.next()) {
            // Retrieve values for Needyusername and Password from each row
            QString Needyusername = query.value("Needyusername").toString();
            QString Password = query.value("Password").toString();
            // Check if the username and password match
            if (Needyusername == username && Password == nppassword) {
                qDebug() << "Login successful for Needyperson:" << Needyusername;
                return true;  // If credentials match, return true
            }
        }
    } else {
        // Handle query execution failure
        qDebug() << "Query failed:" << query.lastError().text();
    }
    // Return false if no match is found
    qDebug() << "Login failed.";
    return false;
}

QString username;

void Np_Log_in::on_nplogin_button_clicked()
{
    username = ui->nploginusernamecheck->text();
    QString password = ui->nploginpasswordcheck->text();

    if (verifyNeedyLogin(username, password)) {
        hide();
        needyperson = new NeedyPerson(this);
        needyperson->show();
    } else {
        // Apply custom QSS style to the QMessageBox for failed login
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Login");
        msgBox.setText("Invalid username or password.");
        msgBox.exec();
    }
}

void Np_Log_in::on_npnewacc_button_clicked()
{
    hide();
    np_sign_in = new Np_Sign_in(this);
    np_sign_in->show();
}

void Np_Log_in::on_pushButton_clicked()
{
    hide();
}
