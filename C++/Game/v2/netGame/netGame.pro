#-------------------------------------------------
#
# Project created by QtCreator 2015-12-23T22:34:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = netGame
TEMPLATE = app


SOURCES += main.cpp\
        player.cpp \
    game.cpp \
    host.cpp \
    guest.cpp \
    card.cpp \
    cardstack.cpp \
    message.cpp

HEADERS  += player.h \
    game.h \
    host.h \
    guest.h \
    card.h \
    cardstack.h \
    message.h


CONFIG += c++11
