#pragma once

#include "Global.h"

#include <QtCore/QEvent>
#include <QtCore/QString>

class COMMON_EXPORT StatusbarEvent : public QEvent
{
    public:
        explicit StatusbarEvent(const QString& message);

        const QString& getMessage() const;

    private:
        QString message;
};
