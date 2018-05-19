#-------------------------------------------------
#
# Project created by QtCreator 2017-10-10T14:41:43
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PopStar_2
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    star.cpp \
    redstar.cpp \
    bluestar.cpp \
    yellowstatr.cpp \
    greenstar.cpp \
    musicthrd.cpp \
    videothrd.cpp \
    popstargame.cpp

HEADERS  += dialog.h \
    star.h \
    redstar.h \
    bluestar.h \
    yellowstatr.h \
    greenstar.h \
    musicthrd.h \
    videothrd.h \
    popstargame.h

FORMS    += dialog.ui \
    popstargame.ui

RESOURCES += \
    images.qrc
CONFIG      +=resources_big

#DESTDIR     +=.\bin  #程序输出路径

RC_FILE     +=Main.rc       #程序图标资源
