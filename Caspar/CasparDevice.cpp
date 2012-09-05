#include "CasparDevice.h"

CasparDevice::CasparDevice(QObject* parent) : AMCPDevice(parent)
{
}

void CasparDevice::connect(const QString& hostname, int port)
{
    AMCPDevice::connectDevice(hostname, port);
}

void CasparDevice::refreshData()
{
    AMCPDevice::writeMessage("DATA LIST");
}

void CasparDevice::refreshMedia()
{
    AMCPDevice::writeMessage("CLS");
}

void CasparDevice::refreshTemplate()
{
    AMCPDevice::writeMessage("TLS");
}

void CasparDevice::clearVideo(int channel)
{
    AMCPDevice::writeMessage(QString("CLEAR %1").arg(channel));
}

void CasparDevice::playVideo(int channel, const QString& item)
{
    AMCPDevice::writeMessage(QString("PLAY %1 %2").arg(channel).arg(item));
}

void CasparDevice::setVolume(float volume, int duration, QString easing)
{
    AMCPDevice::writeMessage(QString("MIXER 1 VOLUME %1 %2 %3").arg(volume).arg(duration).arg(easing));
}

void CasparDevice::setOpacity(float opacity, int duration, QString easing)
{
    AMCPDevice::writeMessage(QString("MIXER 1 OPACITY %1 %2 %3").arg(opacity).arg(duration).arg(easing));
}

void CasparDevice::setBrightness(float brightness, int duration, QString easing)
{
    AMCPDevice::writeMessage(QString("MIXER 1 BRIGHTNESS %1 %2 %3").arg(brightness).arg(duration).arg(easing));
}

void CasparDevice::setContrast(float contrast, int duration, QString easing)
{
    AMCPDevice::writeMessage(QString("MIXER 1 CONTRAST %1 %2 %3").arg(contrast).arg(duration).arg(easing));
}

void CasparDevice::setSaturation(float saturation, int duration, QString easing)
{
    AMCPDevice::writeMessage(QString("MIXER 1 SATURATION %1 %2 %3").arg(saturation).arg(duration).arg(easing));
}

void CasparDevice::setLevels(float minIn, float maxIn, float gamma, float minOut, float maxOut, int duration, QString easing)
{
    AMCPDevice::writeMessage(QString("MIXER 1 LEVELS %1 %2 %3 %4 %5 %6 %7").arg(minIn).arg(maxIn).arg(gamma).arg(minOut).arg(maxOut).arg(duration).arg(easing));
}

void CasparDevice::setGeometry(float x, float y, float sx, float sy, int duration, QString easing)
{
    AMCPDevice::writeMessage(QString("MIXER 1 FILL %1 %2 %3 %4 %5 %6").arg(x).arg(y).arg(sx).arg(sy).arg(duration).arg(easing));
}

void CasparDevice::stopVideo(int channel)
{
    AMCPDevice::writeMessage(QString("STOP %1").arg(channel));
}

void CasparDevice::addTemplate(int channel, int layer, const QString& name, int playOnLoad, const QString& data)
{
    AMCPDevice::writeMessage(QString("CG %1 ADD %2 %3 %4 %5").arg(channel).arg(layer).arg(name).arg(playOnLoad).arg(data));
}

void CasparDevice::playTemplate(int channel, int layer)
{
    AMCPDevice::writeMessage(QString("CG %1 PLAY %2").arg(channel).arg(layer));
}

void CasparDevice::playTemplate(int channel, int layer, const QString& item)
{
    AMCPDevice::writeMessage(QString("CG %1 ADD %2 %3 1").arg(channel).arg(layer).arg(item));
}

void CasparDevice::stopTemplate(int channel, int layer)
{
    AMCPDevice::writeMessage(QString("CG %1 STOP %2").arg(channel).arg(layer));
}

QString CasparDevice::getHostname() const
{
    return AMCPDevice::socket->peerName();
}

int CasparDevice::getPort() const
{
    return AMCPDevice::socket->peerPort();
}

void CasparDevice::sendDeviceNotification()
{
    switch(AMCPDevice::command)
    {
        case AMCPDevice::CLS:
            emit mediaChanged(AMCPDevice::response, *this);
            break;
        case AMCPDevice::TLS:
            emit templateChanged(AMCPDevice::response, *this);
            break;
        case AMCPDevice::CINF:
            emit mediaInfoChanged(AMCPDevice::response, *this);
            break;
        case AMCPDevice::INFO:
            emit infoChanged(AMCPDevice::response, *this);
            break;
        case AMCPDevice::INFOSYSTEM:
            emit infoSystemChanged(AMCPDevice::response, *this);
            break;
        default:
            break;
    }

    AMCPDevice::resetDevice();
}

