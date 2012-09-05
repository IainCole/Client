#-------------------------------------------------
#
# Project created by QtCreator 2011-04-07T13:50:44
#
#-------------------------------------------------

QT += core gui

TARGET = Squeeze
TEMPLATE = lib

DEFINES += SQUEEZE_LIBRARY

HEADERS += \
    SqueezeWidget.h \
    Global.h

SOURCES += \
    SqueezeWidget.cpp

FORMS += \
    SqueezeWidget.ui

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
