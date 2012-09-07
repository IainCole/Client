#-------------------------------------------------
#
# Project created by QtCreator 2011-04-07T13:50:44
#
#-------------------------------------------------

QT += core gui

TARGET = Demo
TEMPLATE = app

RC_FILE = Windows.rc

HEADERS += \
    MainWindow.h \
    AboutDialog.h

SOURCES += \
    MainWindow.cpp \
    Main.cpp \
    AboutDialog.cpp

FORMS += \
    MainWindow.ui \
    AboutDialog.ui

RESOURCES += \
    Resource.qrc

OTHER_FILES += \
    Images/ArrowUpDisabled.png \
    Images/ArrowUp.png \
    Images/ArrowDownDisabled.png \
    Images/ArrowDown.png \
    Stylesheets/Default.css \
    Stylesheets/Extended.css \
    Stylesheets/Windows.css \
    Images/RadiobuttonUncheckedPressed.png \
    Images/RadiobuttonUncheckedHover.png \
    Images/RadiobuttonUnchecked.png \
    Images/RadiobuttonCheckedPressed.png \
    Images/RadiobuttonCheckedHover.png \
    Images/RadiobuttonChecked.png \
    Images/CheckboxUncheckedPressed.png \
    Images/CheckboxUncheckedHover.png \
    Images/CheckboxUnchecked.png \
    Images/CheckboxCheckedPressed.png \
    Images/CheckboxCheckedHover.png \
    Images/CheckboxChecked.png \
    Images/Logo.png \
    Images/CasparCG.png \
    Windows.rc \
    Images/CasparCG.ico \
    Images/ArrowLeftDisabled.png \
    Images/ArrowLeft.png \
    Images/ArrowRightDisabled.png \
    Images/ArrowRight.png \
    Stylesheets/Unix.css

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

DEPENDPATH += $$PWD/../Recorder
INCLUDEPATH += $$PWD/../Recorder
INCLUDEPATH += $$PWD/../../build/Recorder
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Recorder/release/ -lRecorder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Recorder/debug/ -lRecorder
else:unix: LIBS += -L$$OUT_PWD/../Recorder/ -lRecorder

DEPENDPATH += $$PWD/../BigFour
INCLUDEPATH += $$PWD/../BigFour
INCLUDEPATH += $$PWD/../../build/BigFour
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BigFour/release/ -lBigFour
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BigFour/debug/ -lBigFour
else:unix: LIBS += -L$$OUT_PWD/../BigFour/ -lBigFour

DEPENDPATH += $$PWD/../Squeeze
INCLUDEPATH += $$PWD/../Squeeze
INCLUDEPATH += $$PWD/../../build/Squeeze
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Squeeze/release/ -lSqueeze
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Squeeze/debug/ -lSqueeze
else:unix: LIBS += -L$$OUT_PWD/../Squeeze/ -lSqueeze
