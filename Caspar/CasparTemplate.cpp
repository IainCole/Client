#include "CasparTemplate.h"

CasparTemplate::CasparTemplate(const QString& name)
{
    this->name = name;
}

const QString& CasparTemplate::getName() const
{
    return this->name;
}
