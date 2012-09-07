#-------------------------------------------------
#
# Project created by QtCreator 2011-04-07T13:50:44
#
#-------------------------------------------------

QT += core gui

TARGET = Start
TEMPLATE = lib

DEFINES += START_LIBRARY

HEADERS += \
    StartWidget.h \
    Global.h

SOURCES += \
    StartWidget2.cpp

FORMS += \
    StartWidget.ui

RESOURCES += \
    Resource.qrc

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

OTHER_FILES += \
    Images/Picture.png
