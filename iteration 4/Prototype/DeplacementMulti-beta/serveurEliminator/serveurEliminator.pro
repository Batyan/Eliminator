#-------------------------------------------------
#
# Project created by QtCreator 2013-11-23T14:47:24
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = serveurEliminator
CONFIG   += console qt
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    server.cpp \
    playerlight.cpp \
    changemap.cpp

HEADERS += \
    server.h \
    playerlight.h \
    changemap.h
