#-------------------------------------------------
#
# Project created by QtCreator 2017-04-27T06:51:18
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp \
    fileclient.cpp

HEADERS  += mainwindow.h \
    mywidget.h \
    fileclient.h


FORMS    += mainwindow.ui \
    mywidget.ui \
    fileclient.ui

include($$PWD/servers/servers.pri)
INCLUDEPATH += $$PWD/servers


include($$PWD/jsondata/jsondata.pri)
INCLUDEPATH += $$PWD/jsondata
