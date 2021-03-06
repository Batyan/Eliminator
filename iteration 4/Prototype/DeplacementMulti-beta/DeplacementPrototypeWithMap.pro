#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T18:33:08
#
#-------------------------------------------------

QT       += core gui widgets xml
QT       += multimedia multimediawidgets

TARGET = DeplacementPrototypeWithMap
TEMPLATE = app

QMAKE_CXXFLAGS_WARN_ON += -std=c++11

SOURCES += main.cpp\
    gameview.cpp \
    player.cpp \
    gamewindow.cpp \
    entity.cpp \
    spriteimgmove.cpp \
    tile.cpp \
    xmltiledmap.cpp \
    ncpennemy.cpp \
    movableentity.cpp \
    solidentity.cpp \
    mur.cpp \
    levelscene.cpp \
    gamemulti.cpp \
    playerlight.cpp

HEADERS  += \
    gameview.h \
    player.h \
    gamewindow.h \
    entity.h \
    directionmove.h \
    spriteimgmove.h \
    tile.h \
    xmltiledmap.h \
    ncpennemy.h \
    movableentity.h \
    solidentity.h \
    mur.h \
    levelscene.h \
    gamemulti.h \
    playerlight.h

FORMS    +=

RESOURCES += \
    res.qrc
