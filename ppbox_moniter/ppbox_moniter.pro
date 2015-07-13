#-------------------------------------------------
#
# Project created by QtCreator 2015-07-13T16:01:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ppbox_moniter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -lppbox-linux-x64-gcc44-mt-gd-1.1.0

LIBS += -L/usr/local/lib
