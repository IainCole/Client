#pragma once

#include "CasparDevice.h"

#include <QtCore/QList>
#include <QtCore/QObject>

class Connection
{
    public:
        explicit Connection();
        ~Connection();

        static Connection& getInstance();

        void connect(const QString& name, int port = 5250);
        void disconnect();

        CasparDevice& getDevice();

    private:
        CasparDevice* device;
};
