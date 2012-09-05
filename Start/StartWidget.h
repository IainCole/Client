#pragma once

#include "Global.h"

#include "ui_StartWidget.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtGui/QWidget>

class START_EXPORT StartWidget : public QWidget, Ui::StartWidget
{
    Q_OBJECT

    public:
        explicit StartWidget(QWidget* parent = 0);

    protected:
        bool eventFilter(QObject* target, QEvent* event);

    private:
};
