#pragma once

#include "Global.h"

#include "ui_RecorderWidget.h"

#include <QtCore/QTime>
#include <QtCore/QTimer>
#include <QtGui/QWidget>

class RecorderWidget : public QWidget, Ui::RecorderWidget
{
    Q_OBJECT

    public:
        explicit RecorderWidget(QWidget* parent = 0);

    protected:
        bool eventFilter(QObject* target, QEvent* event);

    private:
        QTime time;
        QTimer* timer;
        bool isRecording;

        Q_SLOT void updateTimer();
        Q_SLOT void buttonPressed();
};
