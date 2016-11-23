QT += core
QT -= gui

CONFIG += c++11

TARGET = ColorPoP
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    affichage.cpp

HEADERS += \
    affichage.h \
    constantes.h
