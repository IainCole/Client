#include "CasparVersion.h"

CasparVersion::CasparVersion(const QString& version)
{
    this->version = version;
}

const QString& CasparVersion::getVersion() const
{
    return this->version;
}
