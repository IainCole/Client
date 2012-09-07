#include "Connection.h"

#include "CasparDevice.h"

#include <QtCore/QDebug>
#include <QtCore/QStringList>
#include <QtCore/QTimer>

#include <QtGui/QApplication>

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

void Connection::connect(const QString& name, int port)
{
    if (!this->device->isConnected())
        this->device->connect(name, port);
}

void Connection::disconnect()
{
    if (this->device->isConnected())
        this->device->disconnect();
}
