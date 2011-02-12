#-------------------------------------------------
#
# Project created by QtCreator 2011-01-30T16:37:42
#
#-------------------------------------------------

QT       += core gui

TARGET = qmultilingual
target.path = /usr/local/qmul
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
    settingsdialog.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    language.h \
    multilingual_cli.h \
    english.h \
    deutsch.h \
    czech.h \
    french.h \
    settingsdialog.h \
    about.h

FORMS    += mainwindow.ui \
    settingsdialog.ui \
    about.ui

RESOURCES += \
    resource.qrc


INSTALLS += target

