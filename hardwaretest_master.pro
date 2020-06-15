#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T05:16:51
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hardwaretest_master
TEMPLATE = app

target.path = /usr/bin
INSTALLS += target

SOURCES += main.cpp\
        mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    masterthread.cpp

HEADERS  += mainwindow.h \
    settingsdialog.h \
    console.h \
    masterthread.h

FORMS    += mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    hardwaretest_master.qrc
