/********************************************************************************
** Form generated from reading UI file 'fenserveur.ui'
**
** Created: Mon Sep 5 17:57:15 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENSERVEUR_H
#define UI_FENSERVEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *t_log;
    QVBoxLayout *verticalLayout;
    QTextBrowser *etat;
    QWidget *t_clients;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListView *listePseudo;
    QListView *listePass;
    QListView *listeCo;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(501, 373);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        t_log = new QWidget();
        t_log->setObjectName(QString::fromUtf8("t_log"));
        verticalLayout = new QVBoxLayout(t_log);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        etat = new QTextBrowser(t_log);
        etat->setObjectName(QString::fromUtf8("etat"));

        verticalLayout->addWidget(etat);

        tabWidget->addTab(t_log, QString());
        t_clients = new QWidget();
        t_clients->setObjectName(QString::fromUtf8("t_clients"));
        gridLayout_2 = new QGridLayout(t_clients);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(t_clients);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(t_clients);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(t_clients);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        listePseudo = new QListView(t_clients);
        listePseudo->setObjectName(QString::fromUtf8("listePseudo"));
        listePseudo->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(listePseudo, 1, 0, 1, 1);

        listePass = new QListView(t_clients);
        listePass->setObjectName(QString::fromUtf8("listePass"));
        listePass->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(listePass, 1, 2, 1, 1);

        listeCo = new QListView(t_clients);
        listeCo->setObjectName(QString::fromUtf8("listeCo"));
        listeCo->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(listeCo, 1, 3, 1, 1);

        tabWidget->addTab(t_clients, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 501, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(t_log), QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Pseudo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Pass", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Connecte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(t_clients), QApplication::translate("MainWindow", "Clients", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENSERVEUR_H
