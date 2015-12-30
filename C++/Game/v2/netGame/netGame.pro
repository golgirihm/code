#-------------------------------------------------
#
# Project created by QtCreator 2015-12-23T22:34:08
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = netGame
TEMPLATE = app


SOURCES += main.cpp\
        player.cpp \
    host.cpp \
    guest.cpp \
    card.cpp \
    cardstack.cpp \
    message.cpp \
    netclient.cpp \
    netserver.cpp \
    gameUI.cpp \
    netcomm.cpp

HEADERS  += player.h \
    host.h \
    guest.h \
    card.h \
    cardstack.h \
    message.h \
    netclient.h \
    netserver.h \
    gameUI.h \
    netcomm.h


CONFIG += c++11
