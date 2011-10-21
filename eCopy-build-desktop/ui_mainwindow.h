/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Oct 19 15:29:25 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionSe_reconnecter;
    QAction *actionReduire;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_connexion;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *pseudo_l;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QLineEdit *pass_l;
    QSpacerItem *verticalSpacer;
    QPushButton *inscription_b;
    QPushButton *valider_b;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QWidget *page_inscription;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QWebView *vueInternet;
    QPushButton *retour_b;
    QWidget *page_main;
    QGridLayout *gridLayout_6;
    QLabel *info_l;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QLineEdit *pseudo_search_l;
    QPushButton *chercher_b;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout;
    QPushButton *fichier_b;
    QPushButton *message_b;
    QGroupBox *infos;
    QGridLayout *gridLayout_8;
    QLabel *label_5;
    QLineEdit *found_pseudo;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *found_port;
    QLineEdit *found_co;
    QLineEdit *found_ip;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuECopy;
    QStatusBar *status;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(745, 492);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionSe_reconnecter = new QAction(MainWindow);
        actionSe_reconnecter->setObjectName(QString::fromUtf8("actionSe_reconnecter"));
        actionReduire = new QAction(MainWindow);
        actionReduire->setObjectName(QString::fromUtf8("actionReduire"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_connexion = new QWidget();
        page_connexion->setObjectName(QString::fromUtf8("page_connexion"));
        gridLayout_2 = new QGridLayout(page_connexion);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(page_connexion);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 0, 0, 1, 4);

        pseudo_l = new QLineEdit(groupBox);
        pseudo_l->setObjectName(QString::fromUtf8("pseudo_l"));

        gridLayout_5->addWidget(pseudo_l, 1, 1, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 2, 0, 1, 4);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_3, 3, 0, 1, 1);

        pass_l = new QLineEdit(groupBox);
        pass_l->setObjectName(QString::fromUtf8("pass_l"));
        pass_l->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(pass_l, 3, 1, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 4, 0, 1, 4);

        inscription_b = new QPushButton(groupBox);
        inscription_b->setObjectName(QString::fromUtf8("inscription_b"));
        inscription_b->setStyleSheet(QString::fromUtf8("color:blue;"));

        gridLayout_5->addWidget(inscription_b, 7, 1, 1, 2);

        valider_b = new QPushButton(groupBox);
        valider_b->setObjectName(QString::fromUtf8("valider_b"));

        gridLayout_5->addWidget(valider_b, 5, 0, 2, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 7, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 7, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        stackedWidget->addWidget(page_connexion);
        page_inscription = new QWidget();
        page_inscription->setObjectName(QString::fromUtf8("page_inscription"));
        gridLayout_3 = new QGridLayout(page_inscription);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(page_inscription);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        vueInternet = new QWebView(groupBox_2);
        vueInternet->setObjectName(QString::fromUtf8("vueInternet"));
        vueInternet->setUrl(QUrl("http://localhost/ecopy/inscription.php"));

        gridLayout_4->addWidget(vueInternet, 0, 0, 1, 1);

        retour_b = new QPushButton(groupBox_2);
        retour_b->setObjectName(QString::fromUtf8("retour_b"));

        gridLayout_4->addWidget(retour_b, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        stackedWidget->addWidget(page_inscription);
        page_main = new QWidget();
        page_main->setObjectName(QString::fromUtf8("page_main"));
        gridLayout_6 = new QGridLayout(page_main);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        info_l = new QLabel(page_main);
        info_l->setObjectName(QString::fromUtf8("info_l"));
        info_l->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(info_l, 0, 0, 1, 2);

        groupBox_3 = new QGroupBox(page_main);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pseudo_search_l = new QLineEdit(groupBox_3);
        pseudo_search_l->setObjectName(QString::fromUtf8("pseudo_search_l"));

        gridLayout_7->addWidget(pseudo_search_l, 0, 0, 1, 1);

        chercher_b = new QPushButton(groupBox_3);
        chercher_b->setObjectName(QString::fromUtf8("chercher_b"));

        gridLayout_7->addWidget(chercher_b, 0, 1, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout = new QVBoxLayout(groupBox_6);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        fichier_b = new QPushButton(groupBox_6);
        fichier_b->setObjectName(QString::fromUtf8("fichier_b"));
        fichier_b->setEnabled(false);
        fichier_b->setAutoFillBackground(false);
        fichier_b->setCheckable(false);
        fichier_b->setChecked(false);

        verticalLayout->addWidget(fichier_b);

        message_b = new QPushButton(groupBox_6);
        message_b->setObjectName(QString::fromUtf8("message_b"));
        message_b->setEnabled(false);

        verticalLayout->addWidget(message_b);


        gridLayout_7->addWidget(groupBox_6, 0, 2, 4, 1);

        infos = new QGroupBox(groupBox_3);
        infos->setObjectName(QString::fromUtf8("infos"));
        gridLayout_8 = new QGridLayout(infos);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_5 = new QLabel(infos);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_8->addWidget(label_5, 0, 0, 1, 1);

        found_pseudo = new QLineEdit(infos);
        found_pseudo->setObjectName(QString::fromUtf8("found_pseudo"));
        found_pseudo->setReadOnly(true);

        gridLayout_8->addWidget(found_pseudo, 0, 2, 1, 4);

        label_7 = new QLabel(infos);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_8->addWidget(label_7, 3, 0, 1, 2);

        label_4 = new QLabel(infos);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_8->addWidget(label_4, 5, 0, 1, 1);

        label_6 = new QLabel(infos);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_8->addWidget(label_6, 4, 0, 1, 1);

        found_port = new QLineEdit(infos);
        found_port->setObjectName(QString::fromUtf8("found_port"));
        found_port->setReadOnly(true);

        gridLayout_8->addWidget(found_port, 5, 2, 1, 4);

        found_co = new QLineEdit(infos);
        found_co->setObjectName(QString::fromUtf8("found_co"));
        found_co->setReadOnly(true);

        gridLayout_8->addWidget(found_co, 4, 2, 1, 4);

        found_ip = new QLineEdit(infos);
        found_ip->setObjectName(QString::fromUtf8("found_ip"));
        found_ip->setReadOnly(true);

        gridLayout_8->addWidget(found_ip, 3, 2, 1, 4);


        gridLayout_7->addWidget(infos, 1, 0, 2, 2);

        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(2, 1);

        gridLayout_6->addWidget(groupBox_3, 1, 0, 1, 2);

        gridLayout_6->setRowStretch(0, 1);
        gridLayout_6->setRowStretch(1, 5);
        gridLayout_6->setColumnStretch(0, 2);
        gridLayout_6->setColumnStretch(1, 1);
        stackedWidget->addWidget(page_main);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 745, 25));
        menuECopy = new QMenu(menuBar);
        menuECopy->setObjectName(QString::fromUtf8("menuECopy"));
        MainWindow->setMenuBar(menuBar);
        status = new QStatusBar(MainWindow);
        status->setObjectName(QString::fromUtf8("status"));
        MainWindow->setStatusBar(status);
        QWidget::setTabOrder(pseudo_l, pass_l);
        QWidget::setTabOrder(pass_l, valider_b);
        QWidget::setTabOrder(valider_b, inscription_b);
        QWidget::setTabOrder(inscription_b, pseudo_search_l);
        QWidget::setTabOrder(pseudo_search_l, chercher_b);
        QWidget::setTabOrder(chercher_b, fichier_b);
        QWidget::setTabOrder(fichier_b, message_b);
        QWidget::setTabOrder(message_b, vueInternet);
        QWidget::setTabOrder(vueInternet, retour_b);
        QWidget::setTabOrder(retour_b, found_pseudo);
        QWidget::setTabOrder(found_pseudo, found_port);
        QWidget::setTabOrder(found_port, found_co);
        QWidget::setTabOrder(found_co, found_ip);

        menuBar->addAction(menuECopy->menuAction());
        menuECopy->addAction(actionReduire);
        menuECopy->addAction(actionSe_reconnecter);
        menuECopy->addAction(actionQuitter);

        retranslateUi(MainWindow);
        QObject::connect(pseudo_search_l, SIGNAL(returnPressed()), chercher_b, SLOT(click()));

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionSe_reconnecter->setText(QApplication::translate("MainWindow", "Se reconnecter", 0, QApplication::UnicodeUTF8));
        actionReduire->setText(QApplication::translate("MainWindow", "R\303\251duire", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Identifiez vous:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Mot de passe:", 0, QApplication::UnicodeUTF8));
        inscription_b->setText(QApplication::translate("MainWindow", "Pas encore inscrit ? Faites-le maintenant en moins de 2 minutes !", 0, QApplication::UnicodeUTF8));
        valider_b->setText(QApplication::translate("MainWindow", "Connexion !", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Pseudo:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Inscription:", 0, QApplication::UnicodeUTF8));
        retour_b->setText(QApplication::translate("MainWindow", "Retour", 0, QApplication::UnicodeUTF8));
        info_l->setText(QApplication::translate("MainWindow", "Que faire ?", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Chercher quelqu'un ...", 0, QApplication::UnicodeUTF8));
        pseudo_search_l->setText(QString());
        chercher_b->setText(QApplication::translate("MainWindow", "Chercher", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QString());
        fichier_b->setText(QApplication::translate("MainWindow", "Envoyer un fichier", 0, QApplication::UnicodeUTF8));
        message_b->setText(QApplication::translate("MainWindow", "Discuter", 0, QApplication::UnicodeUTF8));
        infos->setTitle(QApplication::translate("MainWindow", "Informations", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Pseudo :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "IP :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Port :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Connect\303\251 :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "eCopy - Client BETA 0.1", 0, QApplication::UnicodeUTF8));
        menuECopy->setTitle(QApplication::translate("MainWindow", "eCopy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
