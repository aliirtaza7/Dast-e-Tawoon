/********************************************************************************
** Form generated from reading UI file 'ngo.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NGO_H
#define UI_NGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NGO
{
public:
    QLabel *label;
    QListView *messageListView;
    QTextEdit *messageTextEdit;
    QPushButton *sendMessageButton;

    void setupUi(QDialog *NGO)
    {
        if (NGO->objectName().isEmpty())
            NGO->setObjectName("NGO");
        NGO->resize(400, 300);
        label = new QLabel(NGO);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 71, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        messageListView = new QListView(NGO);
        messageListView->setObjectName("messageListView");
        messageListView->setGeometry(QRect(0, 0, 161, 221));
        messageTextEdit = new QTextEdit(NGO);
        messageTextEdit->setObjectName("messageTextEdit");
        messageTextEdit->setGeometry(QRect(160, 130, 231, 111));
        sendMessageButton = new QPushButton(NGO);
        sendMessageButton->setObjectName("sendMessageButton");
        sendMessageButton->setGeometry(QRect(290, 270, 80, 18));

        retranslateUi(NGO);

        QMetaObject::connectSlotsByName(NGO);
    } // setupUi

    void retranslateUi(QDialog *NGO)
    {
        NGO->setWindowTitle(QCoreApplication::translate("NGO", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NGO", "NGO", nullptr));
        sendMessageButton->setText(QCoreApplication::translate("NGO", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NGO: public Ui_NGO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NGO_H
