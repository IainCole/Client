#pragma once

#include "../Shared.h"

#include <QtCore/QEvent>
#include <QtCore/QString>

class CORE_EXPORT OpenRundownEvent : public QEvent
{
    public:
        explicit OpenRundownEvent();
};
