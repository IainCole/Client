#pragma once

#include "Global.h"

#include <QtCore/QString>

class CASPAR_EXPORT CasparData
{
    public:
        explicit CasparData(const QString& name);

        const QString& getName() const;

    private:
        QString name;
};
