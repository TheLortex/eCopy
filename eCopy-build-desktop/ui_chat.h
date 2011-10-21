/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created: Wed Oct 19 15:29:25 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *box_chat;
    QLineEdit *messageAEnvoyer;
    QPushButton *envoyer_b;
    QPushButton *quitter;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(400, 300);
        chat->setModal(false);
        gridLayout = new QGridLayout(chat);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        box_chat = new QTextBrowser(chat);
        box_chat->setObjectName(QString::fromUtf8("box_chat"));

        gridLayout->addWidget(box_chat, 0, 0, 1, 3);

        messageAEnvoyer = new QLineEdit(chat);
        messageAEnvoyer->setObjectName(QString::fromUtf8("messageAEnvoyer"));

        gridLayout->addWidget(messageAEnvoyer, 1, 0, 1, 2);

        envoyer_b = new QPushButton(chat);
        envoyer_b->setObjectName(QString::fromUtf8("envoyer_b"));

        gridLayout->addWidget(envoyer_b, 1, 2, 1, 1);

        quitter = new QPushButton(chat);
        quitter->setObjectName(QString::fromUtf8("quitter"));

        gridLayout->addWidget(quitter, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);


        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QDialog *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Dialog", 0, QApplication::UnicodeUTF8));
        envoyer_b->setText(QApplication::translate("chat", "Envoyer", 0, QApplication::UnicodeUTF8));
        quitter->setText(QApplication::translate("chat", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
