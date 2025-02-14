/********************************************************************************
** Form generated from reading UI file 'np_log_in.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NP_LOG_IN_H
#define UI_NP_LOG_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Np_Log_in
{
public:
    QLabel *nploginheader;
    QGroupBox *nplogingroup;
    QLabel *nploginusername;
    QLabel *nologinpssword;
    QLineEdit *nploginusernamecheck;
    QLineEdit *nploginpasswordcheck;
    QPushButton *nplogin_button;
    QPushButton *npnewacc_button;

    void setupUi(QDialog *Np_Log_in)
    {
        if (Np_Log_in->objectName().isEmpty())
            Np_Log_in->setObjectName("Np_Log_in");
        Np_Log_in->resize(400, 300);
        nploginheader = new QLabel(Np_Log_in);
        nploginheader->setObjectName("nploginheader");
        nploginheader->setGeometry(QRect(10, 10, 131, 31));
        nplogingroup = new QGroupBox(Np_Log_in);
        nplogingroup->setObjectName("nplogingroup");
        nplogingroup->setGeometry(QRect(50, 50, 261, 181));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        font.setBold(true);
        nplogingroup->setFont(font);
        nploginusername = new QLabel(nplogingroup);
        nploginusername->setObjectName("nploginusername");
        nploginusername->setGeometry(QRect(20, 40, 81, 16));
        nologinpssword = new QLabel(nplogingroup);
        nologinpssword->setObjectName("nologinpssword");
        nologinpssword->setGeometry(QRect(20, 60, 81, 16));
        nploginusernamecheck = new QLineEdit(nplogingroup);
        nploginusernamecheck->setObjectName("nploginusernamecheck");
        nploginusernamecheck->setGeometry(QRect(120, 40, 81, 16));
        nploginpasswordcheck = new QLineEdit(nplogingroup);
        nploginpasswordcheck->setObjectName("nploginpasswordcheck");
        nploginpasswordcheck->setGeometry(QRect(120, 60, 81, 16));
        nplogin_button = new QPushButton(nplogingroup);
        nplogin_button->setObjectName("nplogin_button");
        nplogin_button->setGeometry(QRect(200, 130, 51, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(11);
        font1.setBold(false);
        nplogin_button->setFont(font1);
        npnewacc_button = new QPushButton(nplogingroup);
        npnewacc_button->setObjectName("npnewacc_button");
        npnewacc_button->setGeometry(QRect(10, 130, 151, 31));
        npnewacc_button->setFont(font1);

        retranslateUi(Np_Log_in);

        QMetaObject::connectSlotsByName(Np_Log_in);
    } // setupUi

    void retranslateUi(QDialog *Np_Log_in)
    {
        Np_Log_in->setWindowTitle(QCoreApplication::translate("Np_Log_in", "Dialog", nullptr));
        nploginheader->setText(QCoreApplication::translate("Np_Log_in", "Needy people login window ", nullptr));
        nplogingroup->setTitle(QCoreApplication::translate("Np_Log_in", "login in details", nullptr));
        nploginusername->setText(QCoreApplication::translate("Np_Log_in", "Username", nullptr));
        nologinpssword->setText(QCoreApplication::translate("Np_Log_in", "Password", nullptr));
        nplogin_button->setText(QCoreApplication::translate("Np_Log_in", "login", nullptr));
        npnewacc_button->setText(QCoreApplication::translate("Np_Log_in", "don't have an account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Np_Log_in: public Ui_Np_Log_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NP_LOG_IN_H
