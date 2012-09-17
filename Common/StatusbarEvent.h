#pragma once

#include "Global.h"

#include <QtCore/QEvent>

class COMMON_EXPORT StatusbarEvent : public QEvent
{
    public:
        explicit StatusbarEvent(const QString& message, int timeout = 0);

        int getTimeout() const;
        const QString& getMessage() const;

    private:
        int timeout;
        QString message;
};
