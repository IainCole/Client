#include "Connection.h"

#include "CasparDevice.h"

#include <QtCore/QDebug>
#include <QtCore/QStringList>
#include <QtCore/QTimer>

Q_GLOBAL_STATIC(Connection, connection)

Connection::Connection()
{
    this->device = new CasparDevice();
}

Connection::~Connection()
{
    if (this->device->isConnected())
        this->device->disconnect();

    delete this->device;
}

Connection& Connection::getInstance()
{
    return *connection();
}

CasparDevice& Connection::getDevice()
{
    return *this->device;
}
