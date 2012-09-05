#pragma once

#include "Global.h"

#include "AMCPDevice.h"

#include <QtCore/QObject>
#include <QtCore/QString>

class CASPAR_EXPORT CasparDevice : public AMCPDevice
{
    Q_OBJECT

    public:
        explicit CasparDevice(QObject* parent = 0);

        int getPort() const;
        bool isConnected() const;
        QString getHostname() const;

        void connect(const QString& hostname, int port = 5250);

        void addTemplate(int channel, int layer, const QString& name, int playOnLoad, const QString& data);
        void playTemplate(int channel, int layer);
        void playTemplate(int channel, int layer, const QString& item);
        void stopTemplate(int channel, int layer);

        void clearVideo(int channel);
        void playVideo(int channel, const QString& item);
        void stopVideo(int channel);

        void refreshData();
        void refreshMedia();
        void refreshTemplate();

        void setVolume(float volume, int duration, QString easing);
        void setOpacity(float opacity, int duration, QString easing);
        void setBrightness(float brightness, int duration, QString easing);
        void setContrast(float contrast, int duration, QString easing);
        void setSaturation(float saturation, int duration, QString easing);
        void setLevels(float minIn, float maxIn, float gamma, float minOut, float maxOut, int duration, QString easing);
        void setGeometry(float x, float y, float sx, float sy, int duration, QString easing);

        Q_SIGNAL void infoChanged(const QList<QString>&, CasparDevice&);
        Q_SIGNAL void infoSystemChanged(const QList<QString>&, CasparDevice&);
        Q_SIGNAL void mediaChanged(const QList<QString>&, CasparDevice&);
        Q_SIGNAL void mediaInfoChanged(const QList<QString>&, CasparDevice&);
        Q_SIGNAL void templateChanged(const QList<QString>&, CasparDevice&);

    protected:
        void sendDeviceNotification();
};
