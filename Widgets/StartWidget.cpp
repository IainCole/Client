#include "StartWidget.h"

#include "Enum.h"

#include "Connection.h"
#include "StatusbarEvent.h"

StartWidget::StartWidget(QWidget* parent) : QWidget(parent)
{
    setupUi(this);

    qApp->installEventFilter(this);
}

StartWidget::~StartWidget()
{
    if (Connection::getInstance().getDevice().isConnected())
        Connection::getInstance().getDevice().disconnect();
}

bool StartWidget::eventFilter(QObject* target, QEvent* event)
{
    //if(event->type() == static_cast<QEvent::Type>(EventEnum::Statusbar))
    //{
    //    StatusbarEvent* statusbarEvent = static_cast<StatusbarEvent*>(event);
    //    statusBar()->showMessage(statusbarEvent->getMessage(), 5000);
    //}

    return QObject::eventFilter(target, event);
}

void StartWidget::connectDevice()
{
    QObject::connect(&Connection::getInstance().getDevice(), SIGNAL(connectionStateChanged(CasparDevice&)), this, SLOT(deviceConnectionStateChanged(CasparDevice&)));
    QObject::connect(&Connection::getInstance().getDevice(), SIGNAL(versionChanged(const CasparVersion&, CasparDevice&)), this, SLOT(deviceVersionChanged(const CasparVersion&, CasparDevice&)));

    if (this->lineEditPort->text().isEmpty())
        Connection::getInstance().getDevice().connect(this->lineEditName->text());
    else
        Connection::getInstance().getDevice().connect(this->lineEditName->text(), this->lineEditPort->text().toInt());
}

void StartWidget::disconnectDevice()
{
    Connection::getInstance().getDevice().disconnect();
}

void StartWidget::deviceConnectionStateChanged(CasparDevice& device)
{
    if (device.isConnected())
    {
        device.refreshVersion();

        this->pushButtonConnect->setEnabled(false);
        this->pushButtonDisconnect->setEnabled(true);
    }
    else
    {
        this->pushButtonConnect->setEnabled(true);
        this->pushButtonDisconnect->setEnabled(false);

        qApp->postEvent(qApp, new StatusbarEvent(""));
    }
}

void StartWidget::deviceVersionChanged(const CasparVersion& version, CasparDevice& device)
{
    qApp->postEvent(qApp, new StatusbarEvent(QString("Connected to %1 running version %2")
                                             .arg(device.getName()).arg(version.getVersion())));
}
