#pragma once

#include "Global.h"

#include "ui_BigFourWidget.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtGui/QWidget>

class BigFourWidget : public QWidget, Ui::BigFourWidget
{
    Q_OBJECT

    public:
        explicit BigFourWidget(QWidget* parent = 0);

    protected:
        bool eventFilter(QObject* target, QEvent* event);

    private:
};
