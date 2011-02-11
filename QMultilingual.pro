#-------------------------------------------------
#
# Project created by QtCreator 2011-01-30T16:37:42
#
#-------------------------------------------------

QT       += core gui

TARGET = qmultilingual
TEMPLATE = app
CONFIG += console

SOURCES += main.cpp\
        mainwindow.cpp \
    language.cpp \
    multilingual_cli.cpp \
    english.cpp \
    deutsch.cpp \
    czech.cpp \
    french.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    language.h \
    multilingual_cli.h \
    english.h \
    deutsch.h \
    czech.h \
    french.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    settingsdialog.ui
