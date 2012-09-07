#include "StatusbarEvent.h"
#include "Enum.h"

StatusbarEvent::StatusbarEvent(const QString& message) : QEvent(static_cast<QEvent::Type>(Enum::EventType::StatusbarMessage))
{
    this->message = message;
}

const QString& StatusbarEvent::getMessage() const
{
    return this->message;
}
