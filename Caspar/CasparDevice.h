#pragma once

#include "Global.h"

#include "AMCPDevice.h"
#include "CasparMedia.h"
#include "CasparTemplate.h"
#include "CasparVersion.h"
#include "CasparData.h"

class CASPAR_EXPORT CasparDevice : public AMCPDevice
{
    Q_OBJECT

    public:
        explicit CasparDevice(QObject* parent = 0);
        ~CasparDevice();

        void connect(const QString& name, int port = 5250);
        void disconnect();

        int getPort() const;
        QString getName() const;

        void refreshData();
        void refreshMedia();
        void refreshTemplate();
        void refreshVersion();

        void addTemplate(int channel, int flashlayer, const QString& name, int playOnLoad, const QString& data);
        void addTemplate(int channel, int layer, int flashlayer, const QString& name, int playOnLoad, const QString& data);

        void playTemplate(int channel, int flashlayer);
        void playTemplate(int channel, int flashlayer, const QString& item);
        void playTemplate(int channel, int layer, int flashlayer);
        void playTemplate(int channel, int layer, int flashlayer, const QString& item);

        void stopTemplate(int channel, int flashlayer);
        void stopTemplate(int channel, int layer, int flashlayer);

        void clearMedia(int channel);
        void clearMedia(int channel, int layer);

        void playMedia(int channel, const QString& item);
        void playMedia(int channel, int layer, const QString& item);

        void stopMedia(int channel);
        void stopMedia(int channel, int layer);

        void startRecording(int channel, const QString& filename);
        void startRecording(int channel, const QString& filename, const QString& params);
        void startRecording(int channel, int layer, const QString& filename);
        void startRecording(int channel, int layer, const QString& filename, const QString& params);

        void stopRecording(int channel);
        void stopRecording(int channel, int layer);

        void setVolume(int channel, float volume);
        void setVolume(int channel, float volume, int duration, QString easing);
        void setVolume(int channel, int layer, float volume);
        void setVolume(int channel, int layer, float volume, int duration, QString easing);

        void setOpacity(int channel, float opacity);
        void setOpacity(int channel, float opacity, int duration, QString easing);
        void setOpacity(int channel, int layer, float opacity);
        void setOpacity(int channel, int layer, float opacity, int duration, QString easing);

        void setBrightness(int channel, float brightness);
        void setBrightness(int channel, float brightness, int duration, QString easing);
        void setBrightness(int channel, int layer, float brightness);
        void setBrightness(int channel, int layer, float brightness, int duration, QString easing);

        void setContrast(int channel, float contrast);
        void setContrast(int channel, float contrast, int duration, QString easing);
        void setContrast(int channel, int layer, float contrast);
        void setContrast(int channel, int layer, float contrast, int duration, QString easing);

        void setSaturation(int channel, float saturation);
        void setSaturation(int channel, float saturation, int duration, QString easing);
        void setSaturation(int channel, int layer, float saturation);
        void setSaturation(int channel, int layer, float saturation, int duration, QString easing);

        void setLevels(int channel, float minIn, float maxIn, float gamma, float minOut, float maxOut);
        void setLevels(int channel, float minIn, float maxIn, float gamma, float minOut, float maxOut, int duration, QString easing);
        void setLevels(int channel, int layer, float minIn, float maxIn, float gamma, float minOut, float maxOut);
        void setLevels(int channel, int layer, float minIn, float maxIn, float gamma, float minOut, float maxOut, int duration, QString easing);

        void setGeometry(int channel, float positionX, float positionY, float scaleX, float scaleY);
        void setGeometry(int channel, float positionX, float positionY, float scaleX, float scaleY, int duration, QString easing);
        void setGeometry(int channel, int layer, float positionX, float positionY, float scaleX, float scaleY);
        void setGeometry(int channel, int layer, float positionX, float positionY, float scaleX, float scaleY, int duration, QString easing);

        void setClipping(int channel, float positionX, float positionY, float scaleX, float scaleY);
        void setClipping(int channel, float positionX, float positionY, float scaleX, float scaleY, int duration, QString easing);
        void setClipping(int channel, int layer, float positionX, float positionY, float scaleX, float scaleY);
        void setClipping(int channel, int layer, float positionX, float positionY, float scaleX, float scaleY, int duration, QString easing);

        Q_SIGNAL void connectionStateChanged(CasparDevice&);
        Q_SIGNAL void infoChanged(const QList<QString>&, CasparDevice&);
        Q_SIGNAL void infoSystemChanged(const QList<QString>&, CasparDevice&);
        Q_SIGNAL void mediaChanged(const QList<CasparMedia>&, CasparDevice&);
        Q_SIGNAL void mediaInfoChanged(const QList<QString>&, CasparDevice&);
        Q_SIGNAL void templateChanged(const QList<CasparTemplate>&, CasparDevice&);
        Q_SIGNAL void dataChanged(const QList<CasparData>&, CasparDevice&);
        Q_SIGNAL void versionChanged(const CasparVersion&, CasparDevice&);

    protected:
        void sendNotification();
};
