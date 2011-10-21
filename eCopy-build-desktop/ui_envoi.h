/********************************************************************************
** Form generated from reading UI file 'envoi.ui'
**
** Created: Mon Sep 5 18:31:58 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVOI_H
#define UI_ENVOI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_envoi
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *envoi_fichier;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *reception;
    QWidget *transfert;
    QWidget *termine;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QPushButton *quitter_b;

    void setupUi(QDialog *envoi)
    {
        if (envoi->objectName().isEmpty())
            envoi->setObjectName(QString::fromUtf8("envoi"));
        envoi->resize(320, 240);
        envoi->setModal(false);
        gridLayout = new QGridLayout(envoi);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(envoi);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        envoi_fichier = new QWidget();
        envoi_fichier->setObjectName(QString::fromUtf8("envoi_fichier"));
        gridLayout_2 = new QGridLayout(envoi_fichier);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(envoi_fichier);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(envoi_fichier);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        stackedWidget->addWidget(envoi_fichier);
        reception = new QWidget();
        reception->setObjectName(QString::fromUtf8("reception"));
        stackedWidget->addWidget(reception);
        transfert = new QWidget();
        transfert->setObjectName(QString::fromUtf8("transfert"));
        stackedWidget->addWidget(transfert);
        termine = new QWidget();
        termine->setObjectName(QString::fromUtf8("termine"));
        gridLayout_3 = new QGridLayout(termine);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(termine);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        quitter_b = new QPushButton(termine);
        quitter_b->setObjectName(QString::fromUtf8("quitter_b"));

        gridLayout_3->addWidget(quitter_b, 1, 0, 1, 1);

        stackedWidget->addWidget(termine);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(envoi);
        QObject::connect(quitter_b, SIGNAL(clicked()), envoi, SLOT(accept()));

        QMetaObject::connectSlotsByName(envoi);
    } // setupUi

    void retranslateUi(QDialog *envoi)
    {
        envoi->setWindowTitle(QApplication::translate("envoi", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("envoi", "Envoi de fichier", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("envoi", "Choisir les fichiers", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("envoi", "Transfert termin\303\251 !", 0, QApplication::UnicodeUTF8));
        quitter_b->setText(QApplication::translate("envoi", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class envoi: public Ui_envoi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVOI_H
