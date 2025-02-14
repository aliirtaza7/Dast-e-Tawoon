/********************************************************************************
** Form generated from reading UI file 'needyperson.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEEDYPERSON_H
#define UI_NEEDYPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NeedyPerson
{
public:
    QLabel *label;
    QTextEdit *messageTextEdit;
    QListView *listView;
    QPushButton *sendMessage;
    QLabel *label_2;

    void setupUi(QDialog *NeedyPerson)
    {
        if (NeedyPerson->objectName().isEmpty())
            NeedyPerson->setObjectName("NeedyPerson");
        NeedyPerson->resize(533, 429);
        label = new QLabel(NeedyPerson);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 0, 131, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        messageTextEdit = new QTextEdit(NeedyPerson);
        messageTextEdit->setObjectName("messageTextEdit");
        messageTextEdit->setGeometry(QRect(100, 140, 311, 201));
        listView = new QListView(NeedyPerson);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(0, 40, 101, 321));
        sendMessage = new QPushButton(NeedyPerson);
        sendMessage->setObjectName("sendMessage");
        sendMessage->setGeometry(QRect(330, 340, 80, 18));
        label_2 = new QLabel(NeedyPerson);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 91, 41));

        retranslateUi(NeedyPerson);

        QMetaObject::connectSlotsByName(NeedyPerson);
    } // setupUi

    void retranslateUi(QDialog *NeedyPerson)
    {
        NeedyPerson->setWindowTitle(QCoreApplication::translate("NeedyPerson", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NeedyPerson", "Needyperson", nullptr));
        sendMessage->setText(QCoreApplication::translate("NeedyPerson", "SEnd", nullptr));
        label_2->setText(QCoreApplication::translate("NeedyPerson", "NGOs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NeedyPerson: public Ui_NeedyPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEEDYPERSON_H
