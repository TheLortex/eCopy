/********************************************************************************
** Form generated from reading UI file 'transfert.ui'
**
** Created: Fri Oct 21 16:04:40 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERT_H
#define UI_TRANSFERT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transfert
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *envoi_fichier;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *choose_f_b;
    QListView *liste_fichiers;
    QPushButton *quit_b;
    QPushButton *envoi_b;
    QWidget *transfert_tab;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QToolBox *liste_ft;
    QWidget *fichier_1;
    QPushButton *stop_all;
    QWidget *termine;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QPushButton *quitter_b;

    void setupUi(QDialog *transfert)
    {
        if (transfert->objectName().isEmpty())
            transfert->setObjectName(QString::fromUtf8("transfert"));
        transfert->resize(320, 240);
        transfert->setModal(false);
        verticalLayout_2 = new QVBoxLayout(transfert);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(transfert);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        envoi_fichier = new QWidget();
        envoi_fichier->setObjectName(QString::fromUtf8("envoi_fichier"));
        gridLayout_2 = new QGridLayout(envoi_fichier);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(envoi_fichier);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 3);

        choose_f_b = new QPushButton(envoi_fichier);
        choose_f_b->setObjectName(QString::fromUtf8("choose_f_b"));

        gridLayout_2->addWidget(choose_f_b, 1, 0, 2, 2);

        liste_fichiers = new QListView(envoi_fichier);
        liste_fichiers->setObjectName(QString::fromUtf8("liste_fichiers"));

        gridLayout_2->addWidget(liste_fichiers, 3, 0, 1, 3);

        quit_b = new QPushButton(envoi_fichier);
        quit_b->setObjectName(QString::fromUtf8("quit_b"));

        gridLayout_2->addWidget(quit_b, 4, 1, 1, 1);

        envoi_b = new QPushButton(envoi_fichier);
        envoi_b->setObjectName(QString::fromUtf8("envoi_b"));

        gridLayout_2->addWidget(envoi_b, 4, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setRowStretch(3, 3);
        gridLayout_2->setColumnStretch(0, 10);
        stackedWidget->addWidget(envoi_fichier);
        transfert_tab = new QWidget();
        transfert_tab->setObjectName(QString::fromUtf8("transfert_tab"));
        verticalLayout = new QVBoxLayout(transfert_tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(transfert_tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        scrollArea = new QScrollArea(transfert_tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 282, 146));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        liste_ft = new QToolBox(scrollAreaWidgetContents);
        liste_ft->setObjectName(QString::fromUtf8("liste_ft"));
        fichier_1 = new QWidget();
        fichier_1->setObjectName(QString::fromUtf8("fichier_1"));
        fichier_1->setGeometry(QRect(0, 0, 264, 97));
        liste_ft->addItem(fichier_1, QString::fromUtf8("Page 1"));

        gridLayout->addWidget(liste_ft, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        stop_all = new QPushButton(transfert_tab);
        stop_all->setObjectName(QString::fromUtf8("stop_all"));

        verticalLayout->addWidget(stop_all);

        stackedWidget->addWidget(transfert_tab);
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

        verticalLayout_2->addWidget(stackedWidget);


        retranslateUi(transfert);

        stackedWidget->setCurrentIndex(1);
        liste_ft->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(transfert);
    } // setupUi

    void retranslateUi(QDialog *transfert)
    {
        transfert->setWindowTitle(QApplication::translate("transfert", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("transfert", "Envoi de fichier", 0, QApplication::UnicodeUTF8));
        choose_f_b->setText(QApplication::translate("transfert", "Choisir les fichiers", 0, QApplication::UnicodeUTF8));
        quit_b->setText(QApplication::translate("transfert", "Annuler", 0, QApplication::UnicodeUTF8));
        envoi_b->setText(QApplication::translate("transfert", "Envoyer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("transfert", "Transfert en cours :", 0, QApplication::UnicodeUTF8));
        liste_ft->setItemText(liste_ft->indexOf(fichier_1), QApplication::translate("transfert", "Page 1", 0, QApplication::UnicodeUTF8));
        stop_all->setText(QApplication::translate("transfert", "Annuler tout", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("transfert", "Transfert termin\303\251 !", 0, QApplication::UnicodeUTF8));
        quitter_b->setText(QApplication::translate("transfert", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class transfert: public Ui_transfert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERT_H
