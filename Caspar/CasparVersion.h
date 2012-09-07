#pragma once

#include "Global.h"

#include <QtCore/QString>

class CASPAR_EXPORT CasparVersion
{
    public:
        explicit CasparVersion(const QString& version);

        const QString& getVersion() const;

    private:
        QString version;
};
