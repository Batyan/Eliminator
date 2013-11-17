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
    myclient.cpp \
    mywall.cpp

HEADERS  += \
    myserver.h \
    myclient.h \
    mywall.h

FORMS    +=
