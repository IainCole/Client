#include "FrameWidget.h"
#include "Connection.h"

#include <QtCore/QRegExp>

FrameWidget::FrameWidget(QWidget* parent) : QWidget(parent)
{
    setupUi(this);

    qApp->installEventFilter(this);
}

bool FrameWidget::eventFilter(QObject* target, QEvent* event)
{
    //if(event->type() == static_cast<QEvent::Type>(EventEnum::Statusbar))
    //{
    //    StatusbarEvent* statusbarEvent = static_cast<StatusbarEvent*>(event);
    //    statusBar()->showMessage(statusbarEvent->getMessage(), 5000);
    //}

    return QObject::eventFilter(target, event);
}

void FrameWidget::startDemo()
{
    QObject::connect(&Connection::getInstance().getDevice(), SIGNAL(responseChanged(const QList<QString>&, CasparDevice&)), this, SLOT(responseChanged(const QList<QString>&, CasparDevice&)));

    /*QStringList commands = this->plainTextEditCommands->toPlainText().split(QRegExp("\n"));
    foreach (const QString& command, commands)
    {
        if (command.isEmpty() || command.startsWith("//"))
            continue;

        Connection::getInstance().getDevice().sendCommand(command);
    }*/
    // Make sure no graphics are displayed.
    Connection::getInstance().getDevice().sendCommand("CLEAR 1");

    // Mute the volume.
    Connection::getInstance().getDevice().sendCommand("MIXER 1-1 VOLUME 0");
    Connection::getInstance().getDevice().sendCommand("MIXER 1-2 VOLUME 0");

    // Load frame graphics on layer 4.
    Connection::getInstance().getDevice().sendCommand("CG 1-4 ADD 1 FRAME 1");

    // Configure fill rectangle for layer 1.
    Connection::getInstance().getDevice().sendCommand("MIXER 1-1 FILL_RECT 0.43 0.20 0.53 0.53");

    // Configure fill rectangle for layer 2.
    Connection::getInstance().getDevice().sendCommand("MIXER 1-2 FILL_RECT 0.07 0.25 0.42 0.42");

    // Load deinterlaced video on layer 1.
    Connection::getInstance().getDevice().sendCommand("PLAY 1-1 CG1080i50 FILTER YADIF=0:-1 MIX 125 LOOP");

    // Load video on layer 2.
    Connection::getInstance().getDevice().sendCommand("PLAY 1-2 GO1080p25 MIX 125 LOOP");

    // Fade up the volume.
    Connection::getInstance().getDevice().sendCommand("MIXER 1-1 VOLUME 1 25 linear");
    Connection::getInstance().getDevice().sendCommand("MIXER 1-2 VOLUME 1 25 linear");
}

void FrameWidget::stopDemo()
{
    Connection::getInstance().getDevice().clearChannel(1);
}

void FrameWidget::responseChanged(const QList<QString>& response, CasparDevice& device)
{
    foreach (const QString& value, response)
        this->plainTextEditResponse->appendPlainText(value);
}
