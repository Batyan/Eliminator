#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T18:33:08
#
#-------------------------------------------------

QT       += core gui widgets
QT       += multimedia multimediawidgets

TARGET = DeplacementPrototype
TEMPLATE = app

QMAKE_CXXFLAGS_WARN_ON += -std=c++11

SOURCES += main.cpp\
    gamescene.cpp \
    gameview.cpp \
    player.cpp \
    gamewindow.cpp \
    entity.cpp

HEADERS  += \
    gamescene.h \
    gameview.h \
    player.h \
    gamewindow.h \
    entity.h \
    directionmove.h

FORMS    +=

RESOURCES += \
    res.qrc
