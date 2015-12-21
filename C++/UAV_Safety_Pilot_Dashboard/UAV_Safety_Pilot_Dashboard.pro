#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T18:40:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UAV_Safety_Pilot_Dashboard
TEMPLATE = app


SOURCES += main.cpp\
        receiver.cpp

HEADERS  += receiver.h

CONFIG += mobility
MOBILITY = 

FORMS += \
    receiver.ui

