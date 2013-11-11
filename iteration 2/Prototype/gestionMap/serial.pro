#-------------------------------------------------
#
# Project created by QtCreator 2013-11-08T14:45:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serial
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    elementmap.cpp \
    mur.cpp \
    personnage.cpp \
    scene.cpp \
    sauvegarde.cpp

HEADERS  += mainwindow.h \
    elementmap.h \
    mur.h \
    personnage.h \
    scene.h \
    sauvegarde.h

FORMS    += mainwindow.ui
