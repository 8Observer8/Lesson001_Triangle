#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T07:10:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Triangle
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Scene.cpp \
    Triangle.cpp

HEADERS  += Dialog.h \
    Scene.h \
    Triangle.h

FORMS    += Dialog.ui

RESOURCES += \
    Shaders.qrc
