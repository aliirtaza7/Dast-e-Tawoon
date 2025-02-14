#include "np_sign_in.h"
#include "ui_np_sign_in.h"
#include <QDebug>
#include <QMessageBox>

Np_Sign_in::Np_Sign_in(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Np_Sign_in)
{
    ui->setupUi(this);
}

Np_Sign_in::~Np_Sign_in()
{
    delete ui;
}

bool Np_Sign_in::insertNeedySignupData(const QString &username, const QString &password, const QString &cnic, const QString &phone) {
    QSqlQuery query;
    // Prepare the SQL query with placeholders
    query.prepare("INSERT INTO needyperson (Needyusername, Password, CnicNO, PhoneNo) "
                  "VALUES (:username, :password, :cnic, :phone)");

    // Bind the actual values to the placeholders
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":cnic", cnic);
    query.bindValue(":phone", phone);
    // Debugging: log the query to check if the placeholders and values match
    qDebug() << "Executing query: " << query.lastQuery();
    // Execute the query and check if it was successful
    if (!query.exec()) {
        // Log error if the query fails
        qDebug() << "Insert failed: " << query.lastError().text();
        return false;
    }
    // If insertion is successful, log success
    qDebug() << "Data inserted successfully!";
    return true;
}

void Np_Sign_in::on_np_signin_button_clicked()
{
    username = ui->np_signin_username_lineEdit->text();
    QString password = ui->np_signin_pass_lineEdit->text();
    QString cnic = ui->np_cnic_lineEdit->text();
    QString phone = ui->np_phoneno_lineedit->text();

    if (insertNeedySignupData(username, password, cnic, phone)) {
        hide();
        needyperson = new NeedyPerson(this);
        needyperson->show();
    } else {
        // Apply custom QSS style to the QMessageBox for failed sign-up
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Sign-Up");
        msgBox.setText("Sign-Up failed. Please try again.");
        msgBox.exec();
    }
}

void Np_Sign_in::on_pushButton_clicked()
{
    hide();
}

