#pragma once

#include "Global.h"

#include "CasparDevice.h"

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
