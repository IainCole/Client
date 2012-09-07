#pragma once

#include "ui_SqueezeWidget.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtGui/QWidget>

class SqueezeWidget : public QWidget, Ui::SqueezeWidget
{
    Q_OBJECT

    public:
        explicit SqueezeWidget(QWidget* parent = 0);

    protected:
        bool eventFilter(QObject* target, QEvent* event);

    private:
};
