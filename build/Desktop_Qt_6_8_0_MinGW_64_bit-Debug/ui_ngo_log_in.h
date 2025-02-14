/********************************************************************************
** Form generated from reading UI file 'ngo_log_in.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NGO_LOG_IN_H
#define UI_NGO_LOG_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Ngo_Log_in
{
public:
    QGroupBox *groupNgo_log_in;
    QLineEdit *ngouloginusernamecheck;
    QLabel *Ngousernamelogin;
    QLabel *Ngopasswordlogin;
    QLineEdit *ngologinpasswordcheck;
    QPushButton *ngologin_button;
    QPushButton *ngonewacc_button;
    QLabel *ngologinheader;

    void setupUi(QDialog *Ngo_Log_in)
    {
        if (Ngo_Log_in->objectName().isEmpty())
            Ngo_Log_in->setObjectName("Ngo_Log_in");
        Ngo_Log_in->resize(400, 300);
        groupNgo_log_in = new QGroupBox(Ngo_Log_in);
        groupNgo_log_in->setObjectName("groupNgo_log_in");
        groupNgo_log_in->setGeometry(QRect(50, 70, 261, 181));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        font.setBold(true);
        groupNgo_log_in->setFont(font);
        ngouloginusernamecheck = new QLineEdit(groupNgo_log_in);
        ngouloginusernamecheck->setObjectName("ngouloginusernamecheck");
        ngouloginusernamecheck->setGeometry(QRect(120, 50, 113, 20));
        Ngousernamelogin = new QLabel(groupNgo_log_in);
        Ngousernamelogin->setObjectName("Ngousernamelogin");
        Ngousernamelogin->setGeometry(QRect(30, 50, 81, 21));
        Ngopasswordlogin = new QLabel(groupNgo_log_in);
        Ngopasswordlogin->setObjectName("Ngopasswordlogin");
        Ngopasswordlogin->setGeometry(QRect(30, 80, 71, 16));
        ngologinpasswordcheck = new QLineEdit(groupNgo_log_in);
        ngologinpasswordcheck->setObjectName("ngologinpasswordcheck");
        ngologinpasswordcheck->setGeometry(QRect(120, 80, 113, 20));
        ngologin_button = new QPushButton(groupNgo_log_in);
        ngologin_button->setObjectName("ngologin_button");
        ngologin_button->setGeometry(QRect(190, 129, 51, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(11);
        font1.setBold(false);
        ngologin_button->setFont(font1);
        ngonewacc_button = new QPushButton(groupNgo_log_in);
        ngonewacc_button->setObjectName("ngonewacc_button");
        ngonewacc_button->setGeometry(QRect(0, 130, 151, 31));
        ngonewacc_button->setFont(font1);
        ngologinheader = new QLabel(Ngo_Log_in);
        ngologinheader->setObjectName("ngologinheader");
        ngologinheader->setGeometry(QRect(20, 10, 121, 31));

        retranslateUi(Ngo_Log_in);

        QMetaObject::connectSlotsByName(Ngo_Log_in);
    } // setupUi

    void retranslateUi(QDialog *Ngo_Log_in)
    {
        Ngo_Log_in->setWindowTitle(QCoreApplication::translate("Ngo_Log_in", "Dialog", nullptr));
        groupNgo_log_in->setTitle(QCoreApplication::translate("Ngo_Log_in", "Log_in", nullptr));
        Ngousernamelogin->setText(QCoreApplication::translate("Ngo_Log_in", "Username", nullptr));
        Ngopasswordlogin->setText(QCoreApplication::translate("Ngo_Log_in", "Password", nullptr));
        ngologin_button->setText(QCoreApplication::translate("Ngo_Log_in", "login", nullptr));
        ngonewacc_button->setText(QCoreApplication::translate("Ngo_Log_in", "don't have an account", nullptr));
        ngologinheader->setText(QCoreApplication::translate("Ngo_Log_in", "Ngo Login window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ngo_Log_in: public Ui_Ngo_Log_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NGO_LOG_IN_H
