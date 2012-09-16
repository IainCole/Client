#include "StatusbarEvent.h"
#include "Enum.h"

StatusbarEvent::StatusbarEvent(const QString& message, int delay) : QEvent(static_cast<QEvent::Type>(Enum::EventType::StatusbarMessage)),
                                                                    delay(delay), message(message)
{
}

int StatusbarEvent::getDelay() const
{
    return this->delay;
}

const QString& StatusbarEvent::getMessage() const
{
    return this->message;
}
