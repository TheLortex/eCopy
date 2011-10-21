#-------------------------------------------------
#
# Project created by QtCreator 2011-08-07T14:26:18
#
#-------------------------------------------------

QT       += core gui \
network

win32 {
    LIBS += C:\Qt\2010.05\mingw\lib\libmysqlclient.a
}
unix {
    LIBS += /usr/lib/libmysqlclient.a
}

TARGET = eCopy_server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    passerelle.cpp

HEADERS  += mainwindow.h \
    passerelle.h

FORMS    += mainwindow.ui
