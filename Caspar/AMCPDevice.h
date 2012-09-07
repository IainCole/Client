#pragma once

#include "Global.h"

#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QTcpSocket>

class CASPAR_EXPORT AMCPDevice : public QObject
{
    Q_OBJECT

    public:
        explicit AMCPDevice(QObject* parent = 0);
        ~AMCPDevice();

        bool isConnected() const;

    protected:
        enum AMCPCommand
        {
            NONE,
            CONNECTIONSTATE,
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
            DATA,
            CLEAR,
            SET,
            MIXER,
            CALL,
            REMOVE,
            ADD,
            SWAP,
            STATUS
        };

        QTcpSocket* socket;
        AMCPCommand command;

        QList<QString> response;

        virtual void sendNotification() = 0;

        void connectDevice(const QString& ip, int port);
        void disconnectDevice();

        void resetDevice();
        void writeMessage(const QString& message);

    private:
        enum AMCPParserState
        {
            ExpectingHeader,
            ExpectingSingleline,
            ExpectingMultiline
        };

        bool connected;
        int code, state;
        QString line, previousLine;

        void parseLine(const QString& line);
        void parseHeader(const QString& line);
        void parseSingleline(const QString& line);
        void parseMultiline(const QString& line);

        AMCPCommand translateCommand(const QString& command);

        Q_SLOT void readMessage();
        Q_SLOT void setConnected();
        Q_SLOT void setDisconnected();
};
