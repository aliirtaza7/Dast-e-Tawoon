#include "ngo_sign_in.h"
#include "ui_ngo_sign_in.h"
#include <QMessageBox>
#include <QDebug>

Ngo_Sign_in::Ngo_Sign_in(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Ngo_Sign_in)
{
    ui->setupUi(this);
}

Ngo_Sign_in::~Ngo_Sign_in()
{
    delete ui;
}

bool Ngo_Sign_in::insertNGOSignupData(const QString &reg, const QString &username, const QString &password)
{
    // Create a QSqlQuery object to handle the SQL query
    QSqlQuery query;
    // Prepare the SQL query string with placeholders
    query.prepare("INSERT INTO ngo (RegistrationNo, NgoName, NgoPassword) "
                  "VALUES (:registration, :username, :password)");
    // Bind values to the placeholders in the query
    query.bindValue(":registration", reg);  // Ensure this matches the column name in your table
    query.bindValue(":username", username); // Ensure this matches the column name in your table
    query.bindValue(":password", password); // Ensure this matches the column name in your table

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

void Ngo_Sign_in::on_ngo_signin_pushButton_clicked()
{
    QString username = ui->ngoname_lineEdit->text();
    QString password = ui->ngo_password_lineedit->text();
    QString reg = ui->ngoregistrationNolineEdit->text();

    if (insertNGOSignupData(reg, username, password)) {
        hide();
        ngo = new NGO(this);
        ngo->show();
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

void Ngo_Sign_in::on_pushButton_clicked()
{
    hide();
}

