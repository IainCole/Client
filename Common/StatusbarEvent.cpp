#include "StatusbarEvent.h"
#include "EventEnum.h"

StatusbarEvent::StatusbarEvent(const QString& message) : QEvent(static_cast<QEvent::Type>(EventEnum::Statusbar))
{
    this->message = message;
}

const QString& StatusbarEvent::getMessage() const
{
    return this->message;
}
