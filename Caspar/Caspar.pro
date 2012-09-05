#-------------------------------------------------
#
# Project created by QtCreator 2012-04-12T13:07:49
#
#-------------------------------------------------

QT -= gui
QT += network

TARGET = Caspar
TEMPLATE = lib

DEFINES += CASPAR_LIBRARY

SOURCES += \
    CasparDevice.cpp \
    AMCPDevice.cpp

HEADERS += \
    Global.h \
    CasparDevice.h \
    AMCPDevice.h
