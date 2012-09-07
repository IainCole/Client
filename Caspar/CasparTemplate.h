#pragma once

#include "Global.h"

#include <QtCore/QString>

class CASPAR_EXPORT CasparTemplate
{
    public:
        explicit CasparTemplate(const QString& name);

        const QString& getName() const;

    private:
        QString name;
};
