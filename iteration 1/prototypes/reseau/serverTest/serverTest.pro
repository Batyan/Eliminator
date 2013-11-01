#-------------------------------------------------
#
# Project created by QtCreator 2013-10-23T19:25:50
#
#-------------------------------------------------

QT       += core gui
QT  += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serverTest
TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    mythread.cpp \
    myclient.cpp

HEADERS  += \
    myserver.h \
    mythread.h \
    myclient.h

FORMS    +=
