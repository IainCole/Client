#include "StartWidget.h"
#include "StatusbarEvent.h"

#include <QtCore/QDebug>
#include <QtCore/QString>

StartWidget::StartWidget(QWidget* parent) : QWidget(parent)
{
    setupUi(this);

    StatusbarEvent* event = new StatusbarEvent("Loading start screen");
    qApp->postEvent(qApp, event);

    qApp->installEventFilter(this);
}

bool StartWidget::eventFilter(QObject* target, QEvent* event)
{
    //if(event->type() == static_cast<QEvent::Type>(EventEnum::Statusbar))
    //{
    //    StatusbarEvent* statusbarEvent = static_cast<StatusbarEvent*>(event);
    //    statusBar()->showMessage(statusbarEvent->getMessage(), 5000);
    //}

    return QObject::eventFilter(target, event);
}
