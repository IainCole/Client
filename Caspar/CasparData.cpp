#include "CasparData.h"

CasparData::CasparData(const QString& name)
{
    this->name = name;
}

const QString& CasparData::getName() const
{
    return this->name;
}
