#include "SqueezeWidget.h"
#include "StatusbarEvent.h"

#include <QtCore/QDebug>
#include <QtCore/QString>

SqueezeWidget::SqueezeWidget(QWidget* parent) : QWidget(parent)
{
    setupUi(this);

    StatusbarEvent* event = new StatusbarEvent("Loading squeeze demo");
    qApp->postEvent(qApp, event);

    this->device = new CasparDevice();
    this->device->connect("localhost");

    qApp->installEventFilter(this);
}

bool SqueezeWidget::eventFilter(QObject* target, QEvent* event)
{
    //if(event->type() == static_cast<QEvent::Type>(EventEnum::Statusbar))
    //{
    //    StatusbarEvent* statusbarEvent = static_cast<StatusbarEvent*>(event);
    //    statusBar()->showMessage(statusbarEvent->getMessage(), 5000);
    //}

    return QObject::eventFilter(target, event);
}

void SqueezeWidget::startDemo()
{
    this->device->playVideo(1, "NG");
}
