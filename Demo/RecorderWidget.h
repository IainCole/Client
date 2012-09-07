#pragma once

#include "ui_RecorderWidget.h"

#include <QtGui/QWidget>

class RecorderWidget : public QWidget, Ui::RecorderWidget
{
    Q_OBJECT

    public:
        explicit RecorderWidget(QWidget* parent = 0);

    protected:
        bool eventFilter(QObject* target, QEvent* event);

    private:
        Q_SLOT void updateTime();
        Q_SLOT void buttonPressed();
};
