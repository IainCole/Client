#pragma once

#include "Global.h"

#include <QtCore/QEvent>

class COMMON_EXPORT StatusbarEvent : public QEvent
{
    public:
        explicit StatusbarEvent(const QString& message, int delay = 3000);

        int getDelay() const;
        const QString& getMessage() const;

    private:
        int delay;
        QString message;
};
