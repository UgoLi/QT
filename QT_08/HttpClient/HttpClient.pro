#-------------------------------------------------
#
# Project created by QtCreator 2017-09-19T09:27:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HttpClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    LoginDialog.cpp

HEADERS  += mainwindow.h \
    LoginDialog.h

FORMS    += mainwindow.ui \
    LoginDialog.ui
