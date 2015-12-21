#-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T19:00:10
#
#-------------------------------------------------

QT       += core gui \
    multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tutorial1_Youtube
TEMPLATE = app


SOURCES += main.cpp \
    Player.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp

HEADERS  += \
    Player.h \
    Enemy.h \
    Bullet.h \
    Game.h \
    Score.h \
    Health.h

RESOURCES += \
    resource.qrc

DISTFILES +=
