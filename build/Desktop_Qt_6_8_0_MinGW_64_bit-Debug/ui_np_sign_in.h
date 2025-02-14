/********************************************************************************
** Form generated from reading UI file 'np_sign_in.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NP_SIGN_IN_H
#define UI_NP_SIGN_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Np_Sign_in
{
public:
    QLabel *label;
    QGroupBox *np_signin_groupBox;
    QLineEdit *np_signin_username_lineEdit;
    QLineEdit *np_signin_pass_lineEdit;
    QLineEdit *np_cnic_lineEdit;
    QLineEdit *np_phoneno_lineedit;
    QLabel *np_signin_username;
    QLabel *np_signin_password;
    QLabel *np_signin_cnic;
    QLabel *np_phoneno;
    QPushButton *np_signin_button;
    QPushButton *pushButton;

    void setupUi(QDialog *Np_Sign_in)
    {
        if (Np_Sign_in->objectName().isEmpty())
            Np_Sign_in->setObjectName("Np_Sign_in");
        Np_Sign_in->resize(400, 300);
        label = new QLabel(Np_Sign_in);
        label->setObjectName("label");
        label->setGeometry(QRect(30, -10, 231, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        np_signin_groupBox = new QGroupBox(Np_Sign_in);
        np_signin_groupBox->setObjectName("np_signin_groupBox");
        np_signin_groupBox->setGeometry(QRect(70, 60, 291, 221));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(12);
        font1.setBold(true);
        np_signin_groupBox->setFont(font1);
        np_signin_username_lineEdit = new QLineEdit(np_signin_groupBox);
        np_signin_username_lineEdit->setObjectName("np_signin_username_lineEdit");
        np_signin_username_lineEdit->setGeometry(QRect(140, 40, 131, 21));
        np_signin_pass_lineEdit = new QLineEdit(np_signin_groupBox);
        np_signin_pass_lineEdit->setObjectName("np_signin_pass_lineEdit");
        np_signin_pass_lineEdit->setGeometry(QRect(140, 70, 131, 21));
        np_cnic_lineEdit = new QLineEdit(np_signin_groupBox);
        np_cnic_lineEdit->setObjectName("np_cnic_lineEdit");
        np_cnic_lineEdit->setGeometry(QRect(140, 100, 131, 21));
        np_phoneno_lineedit = new QLineEdit(np_signin_groupBox);
        np_phoneno_lineedit->setObjectName("np_phoneno_lineedit");
        np_phoneno_lineedit->setGeometry(QRect(140, 130, 131, 21));
        np_signin_username = new QLabel(np_signin_groupBox);
        np_signin_username->setObjectName("np_signin_username");
        np_signin_username->setGeometry(QRect(10, 40, 91, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(10);
        font2.setBold(false);
        np_signin_username->setFont(font2);
        np_signin_password = new QLabel(np_signin_groupBox);
        np_signin_password->setObjectName("np_signin_password");
        np_signin_password->setGeometry(QRect(10, 70, 91, 16));
        np_signin_password->setFont(font2);
        np_signin_cnic = new QLabel(np_signin_groupBox);
        np_signin_cnic->setObjectName("np_signin_cnic");
        np_signin_cnic->setGeometry(QRect(10, 100, 91, 16));
        np_signin_cnic->setFont(font2);
        np_phoneno = new QLabel(np_signin_groupBox);
        np_phoneno->setObjectName("np_phoneno");
        np_phoneno->setGeometry(QRect(10, 130, 91, 16));
        np_phoneno->setFont(font2);
        np_signin_button = new QPushButton(np_signin_groupBox);
        np_signin_button->setObjectName("np_signin_button");
        np_signin_button->setGeometry(QRect(160, 180, 80, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(11);
        font3.setBold(true);
        np_signin_button->setFont(font3);
        pushButton = new QPushButton(Np_Sign_in);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 21, 21));

        retranslateUi(Np_Sign_in);

        QMetaObject::connectSlotsByName(Np_Sign_in);
    } // setupUi

    void retranslateUi(QDialog *Np_Sign_in)
    {
        Np_Sign_in->setWindowTitle(QCoreApplication::translate("Np_Sign_in", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Np_Sign_in", "Sign in as Needy Person", nullptr));
        np_signin_groupBox->setTitle(QCoreApplication::translate("Np_Sign_in", "Sign in details:", nullptr));
        np_cnic_lineEdit->setText(QString());
        np_signin_username->setText(QCoreApplication::translate("Np_Sign_in", "Username:", nullptr));
        np_signin_password->setText(QCoreApplication::translate("Np_Sign_in", "Password :", nullptr));
        np_signin_cnic->setText(QCoreApplication::translate("Np_Sign_in", "Cnic No:", nullptr));
        np_phoneno->setText(QCoreApplication::translate("Np_Sign_in", "Phone No:", nullptr));
        np_signin_button->setText(QCoreApplication::translate("Np_Sign_in", "Sign in", nullptr));
        pushButton->setText(QCoreApplication::translate("Np_Sign_in", "<--", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Np_Sign_in: public Ui_Np_Sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NP_SIGN_IN_H
