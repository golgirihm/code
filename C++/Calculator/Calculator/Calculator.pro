#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T14:06:39
#
#-------------------------------------------------

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    Complex.cpp \
    functions.cpp

HEADERS  += mainwindow.h \
    Complex.h \
    functions.h \
    global.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY =

