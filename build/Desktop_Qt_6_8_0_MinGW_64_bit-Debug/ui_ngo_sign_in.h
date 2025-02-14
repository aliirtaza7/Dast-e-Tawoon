/********************************************************************************
** Form generated from reading UI file 'ngo_sign_in.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NGO_SIGN_IN_H
#define UI_NGO_SIGN_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Ngo_Sign_in
{
public:
    QLabel *ngosigninheader;
    QGroupBox *NgosigningroupBox;
    QLabel *Ngoregistration;
    QLineEdit *ngoregistrationNolineEdit;
    QLabel *ngoname_signin;
    QLineEdit *ngoname_lineEdit;
    QLineEdit *ngo_password_lineedit;
    QLabel *ngo_signin_password;
    QPushButton *ngo_signin_pushButton;

    void setupUi(QDialog *Ngo_Sign_in)
    {
        if (Ngo_Sign_in->objectName().isEmpty())
            Ngo_Sign_in->setObjectName("Ngo_Sign_in");
        Ngo_Sign_in->resize(400, 300);
        ngosigninheader = new QLabel(Ngo_Sign_in);
        ngosigninheader->setObjectName("ngosigninheader");
        ngosigninheader->setGeometry(QRect(10, 10, 221, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        font.setBold(true);
        ngosigninheader->setFont(font);
        NgosigningroupBox = new QGroupBox(Ngo_Sign_in);
        NgosigningroupBox->setObjectName("NgosigningroupBox");
        NgosigningroupBox->setGeometry(QRect(40, 50, 301, 191));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(12);
        font1.setBold(true);
        NgosigningroupBox->setFont(font1);
        Ngoregistration = new QLabel(NgosigningroupBox);
        Ngoregistration->setObjectName("Ngoregistration");
        Ngoregistration->setGeometry(QRect(20, 50, 101, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(11);
        font2.setBold(false);
        Ngoregistration->setFont(font2);
        ngoregistrationNolineEdit = new QLineEdit(NgosigningroupBox);
        ngoregistrationNolineEdit->setObjectName("ngoregistrationNolineEdit");
        ngoregistrationNolineEdit->setGeometry(QRect(170, 50, 113, 20));
        ngoname_signin = new QLabel(NgosigningroupBox);
        ngoname_signin->setObjectName("ngoname_signin");
        ngoname_signin->setGeometry(QRect(20, 80, 91, 16));
        ngoname_signin->setFont(font2);
        ngoname_lineEdit = new QLineEdit(NgosigningroupBox);
        ngoname_lineEdit->setObjectName("ngoname_lineEdit");
        ngoname_lineEdit->setGeometry(QRect(170, 80, 113, 20));
        ngo_password_lineedit = new QLineEdit(NgosigningroupBox);
        ngo_password_lineedit->setObjectName("ngo_password_lineedit");
        ngo_password_lineedit->setGeometry(QRect(170, 110, 113, 20));
        ngo_signin_password = new QLabel(NgosigningroupBox);
        ngo_signin_password->setObjectName("ngo_signin_password");
        ngo_signin_password->setGeometry(QRect(20, 110, 81, 16));
        ngo_signin_password->setFont(font2);
        ngo_signin_pushButton = new QPushButton(NgosigningroupBox);
        ngo_signin_pushButton->setObjectName("ngo_signin_pushButton");
        ngo_signin_pushButton->setGeometry(QRect(190, 150, 81, 31));

        retranslateUi(Ngo_Sign_in);

        QMetaObject::connectSlotsByName(Ngo_Sign_in);
    } // setupUi

    void retranslateUi(QDialog *Ngo_Sign_in)
    {
        Ngo_Sign_in->setWindowTitle(QCoreApplication::translate("Ngo_Sign_in", "Dialog", nullptr));
        ngosigninheader->setText(QCoreApplication::translate("Ngo_Sign_in", "Sign in as NGO", nullptr));
        NgosigningroupBox->setTitle(QCoreApplication::translate("Ngo_Sign_in", "Sign in Details", nullptr));
        Ngoregistration->setText(QCoreApplication::translate("Ngo_Sign_in", "Registration NO:", nullptr));
        ngoname_signin->setText(QCoreApplication::translate("Ngo_Sign_in", "Ngo Name:", nullptr));
        ngoname_lineEdit->setText(QString());
        ngo_signin_password->setText(QCoreApplication::translate("Ngo_Sign_in", "Password", nullptr));
        ngo_signin_pushButton->setText(QCoreApplication::translate("Ngo_Sign_in", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ngo_Sign_in: public Ui_Ngo_Sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NGO_SIGN_IN_H
