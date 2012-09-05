#pragma once

#include "Global.h"

#include <QtCore/QEvent>

class COMMON_EXPORT EventEnum
{
    public:
        enum EventType
        {
            Statusbar = QEvent::User + 1,
            RundownItemSelected = QEvent::User + 2
        };
};
