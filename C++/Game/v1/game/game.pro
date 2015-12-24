#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T17:56:18
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    server.cpp \
    client.cpp \
    lobby.cpp \
    mainscreen.cpp \
    message.cpp

HEADERS  += game.h \
    server.h \
    client.h \
    lobby.h \
    mainscreen.h \
    message.h \

FORMS    += \
    game.ui \
    lobby.ui \
    mainscreen.ui

DISTFILES +=

CONFIG += c++11

