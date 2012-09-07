#-------------------------------------------------
#
# Project created by QtCreator 2011-04-07T13:50:44
#
#-------------------------------------------------

QT += core gui

TARGET = Recorder
TEMPLATE = lib

DEFINES += RECORDER_LIBRARY

HEADERS += \
    Global.h \
    RecorderWidget.h

SOURCES += \
    RecorderWidget.cpp

FORMS += \
    RecorderWidget.ui

RESOURCES += \
    Resource.qrc

OTHER_FILES += \
    Images/FastForwardEnd.png \
    Images/FastRewindStart.png \
    Images/Play.png \
    Images/FastForward.png \
    Images/FastRewind.png \
    Images/Record.png \
    Images/Stop.png \
    Images/Pause.png

DEPENDPATH += $$PWD/../Caspar
INCLUDEPATH += $$PWD/../Caspar
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Caspar/release/ -lCaspar
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Caspar/debug/ -lCaspar
else:unix: LIBS += -L$$OUT_PWD/../Caspar/ -lCaspar

DEPENDPATH += $$PWD/../Common
INCLUDEPATH += $$PWD/../Common
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Common/release/ -lCommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Common/debug/ -lCommon
else:unix: LIBS += -L$$OUT_PWD/../Common/ -lCommon
