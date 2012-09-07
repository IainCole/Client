#pragma once

#include "ui_MainWindow.h"

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
        void enableDemoButton(const QString& buttonName);

        Q_SLOT void showAboutDialog();
        Q_SLOT void showStart();
        Q_SLOT void showSqueeze();
};
