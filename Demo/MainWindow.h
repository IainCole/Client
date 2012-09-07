#pragma once

#include "ui_MainWindow.h"

#include "CasparDevice.h"
#include "CasparVersion.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = 0);

    protected:
        bool eventFilter(QObject* target, QEvent* event);

    private:
        void setupUiMenu();
        void removeWidgets();
        void enableDemoButton(const QString& buttonName);

        Q_SLOT void showAboutDialog();
        Q_SLOT void showRecorder();
        Q_SLOT void showBigFour();
        Q_SLOT void showSqueeze();
        Q_SLOT void connectDevice();
        Q_SLOT void disconnectDevice();
        Q_SLOT void deviceConnectionStateChanged(CasparDevice&);
        Q_SLOT void deviceVersionChanged(const CasparVersion&, CasparDevice&);
};
