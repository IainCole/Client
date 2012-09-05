#pragma once

#include "Global.h"

#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QTcpSocket>

class AMCPDevice : public QObject
{
    Q_OBJECT

    public:
        bool isConnected() const;

        virtual void sendDeviceNotification() = 0;

    protected:
        explicit AMCPDevice(QObject* parent = 0);
        ~AMCPDevice();

        enum AMCPCommand
        {
            NONE,
            LOAD,
            LOADBG,
            PLAY,
            STOP,
            CG,
            CLS,
            CINF,
            VERSION,
            TLS,
            INFO,
            INFOSYSTEM,
            DATA
        };

        QTcpSocket* socket;
        AMCPCommand command;

        QList<QString> response;

        void resetDevice();
        void writeMessage(const QString& message);
        void connectDevice(const QString& hostname, int port);

    private:
        enum AMCPParserState
        {
            ExpectingHeader,
            ExpectingSingleline,
            ExpectingMultiline
        };

        bool connected;
        int code, state;
        QString previousLine;

        void parseLine(const QString& line);
        void parseHeader(const QString& line);
        void parseSingleline(const QString& line);
        void parseMultiline(const QString& line);

        AMCPCommand translateCommand(const QString& command);

        Q_SLOT void readMessage();
        Q_SLOT void setConnected();
        Q_SLOT void setDisconnected();
};
