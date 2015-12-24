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
    card.cpp \
    cardstack.cpp \
    Communications/net_server.cpp \
    Communications/net_client.cpp \
    Communications/message.cpp \
    Forms_Code/mainscreen.cpp \
    Forms_Code/lobby.cpp

HEADERS  += game.h \
    card.h \
    cardstack.h \
    Communications/net_client.h \
    Communications/net_server.h \
    Communications/message.h \
    Forms_Code/mainscreen.h \
    Forms_Code/lobby.h

FORMS    += \
    game.ui \
    lobby.ui \
    mainscreen.ui

DISTFILES +=

CONFIG += c++11
