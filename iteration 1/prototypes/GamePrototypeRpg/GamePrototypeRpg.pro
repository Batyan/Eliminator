#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T18:33:08
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GamePrototypeRpg
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamescene.cpp \
    gameview.cpp \
    player.cpp \
    ncp.cpp

HEADERS  += mainwindow.h \
    gamescene.h \
    gameview.h \
    player.h \
    ncp.h

FORMS    +=

RESOURCES += \
    res.qrc
