#-------------------------------------------------
#
# Project created by QtCreator 2011-08-06T18:10:41
#
#-------------------------------------------------

QT       += core gui \
 network \
webkit

TARGET = eCopy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fichier.cpp \
    network.cpp \
    chat.cpp \
    netpass.cpp \
    transfert.cpp \
    ft_widget.cpp

HEADERS  += mainwindow.h \
    fichier.h \
    network.h \
    chat.h \
    netpass.h \
    transfert.h \
    ft_widget.h

FORMS    += mainwindow.ui \
    chat.ui \
    transfert.ui \
    ft_widget.ui



