#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T14:14:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Keyboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylineedit.cpp \
    signupdialog.cpp \
    videodialog.cpp

HEADERS  += mainwindow.h \
    mylineedit.h \
    signupdialog.h \
    videodialog.h

FORMS    += mainwindow.ui \
    signupdialog.ui \
    videodialog.ui

RESOURCES += \
    BASIC.qrc
