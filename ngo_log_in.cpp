#include "ngo_log_in.h"
#include "ui_ngo_log_in.h"
#include <QMessageBox>
#include "databasemanagement.h"

Ngo_Log_in::Ngo_Log_in(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Ngo_Log_in)
{
    ui->setupUi(this);
    dbmanagement.connectToDatabase();
}

Ngo_Log_in::~Ngo_Log_in()
{
    delete ui;
}

bool Ngo_Log_in::verifyNGOLogin(const QString &username, const QString &password)
{
    // Prepare your query to select from the 'ngo' table
    QSqlQuery query;
    // Execute the query
    if (query.exec("SELECT * FROM ngo")) {
        // Loop through all rows in the result set
        while (query.next()) {
            // Retrieve values for NgoName and NgoPassword from each row
            QString ngoName = query.value("NgoName").toString();
            QString ngoPassword = query.value("NgoPassword").toString();
            // Check if the username and password match
            if (ngoName == username && ngoPassword == password) {
                qDebug() << "Login successful for NGO:" << ngoName;
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

void Ngo_Log_in::on_ngologin_button_clicked()
{
    QString username = ui->ngouloginusernamecheck->text();
    QString password = ui->ngologinpasswordcheck->text();

    if (verifyNGOLogin(username ,password)) {
        ngo = new NGO(this);
        ngo->show();
        hide();
    } else {
        // Apply custom QSS style to the QMessageBox for invalid login
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

void Ngo_Log_in::on_ngonewacc_button_clicked()
{
    hide();
    ngo_sign_in = new Ngo_Sign_in(this);
    ngo_sign_in->show();
}

void Ngo_Log_in::on_pushButton_clicked()
{
    hide();
}
