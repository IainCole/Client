#pragma once

#include "Global.h"
#include "CasparDevice.h"

#include "ui_SqueezeWidget.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtGui/QWidget>

class SQUEEZE_EXPORT SqueezeWidget : public QWidget, Ui::SqueezeWidget
{
    Q_OBJECT

    public:
        explicit SqueezeWidget(QWidget* parent = 0);

    protected:
        bool eventFilter(QObject* target, QEvent* event);

    private:
        CasparDevice* device;

        Q_SLOT void startDemo();
};
