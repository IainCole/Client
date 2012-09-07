#include "MainWindow.h"
#include "Global.h"
#include "Connection.h"
#include "AboutDialog.h"
#include "Enum.h"
#include "StatusbarEvent.h"
#include "RecorderWidget.h"
#include "BigFourWidget.h"
#include "SqueezeWidget.h"

#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtGui/QDesktopWidget>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QMouseEvent>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    setupUi(this);
    setupUiMenu();
    setWindowIcon(QIcon(":/Graphics/Images/CasparCG.ico"));
    setWindowTitle(QString("%1 %2.%3").arg(this->windowTitle()).arg(MAJOR_VERSION).arg(MINOR_VERSION));

    qApp->installEventFilter(this);
}

void MainWindow::setupUiMenu()
{
     QMenu* fileMenu = new QMenu(this);
     fileMenu->addAction("&Quit", this, SLOT(close()), QKeySequence::fromString("Ctrl+Q"));

     QMenu* helpMenu = new QMenu(this);
     helpMenu->addAction("&About CasparCG Demo", this, SLOT(showAboutDialog()), QKeySequence::fromString("Ctrl+A"));

     QMenuBar* menuBar = new QMenuBar(this);
     menuBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
     menuBar->addMenu(fileMenu)->setText("&File");
     menuBar->addMenu(helpMenu)->setText("&Help");

     this->setMenuBar(menuBar);
}

bool MainWindow::eventFilter(QObject* target, QEvent* event)
{
    if(event->type() == static_cast<QEvent::Type>(Enum::EventType::StatusbarMessage))
    {
        StatusbarEvent* statusbarEvent = static_cast<StatusbarEvent*>(event);
        statusBar()->showMessage(statusbarEvent->getMessage(), 1000);
    }

    return QObject::eventFilter(target, event);
}

void MainWindow::removeWidgets()
{
    while(!this->frameWidgets->layout()->isEmpty())
        delete this->frameWidgets->layout()->takeAt(0)->widget();
}

void MainWindow::enableDemoButton(const QString& buttonName)
{
    removeWidgets();

    foreach(QPushButton* button, this->findChildren<QPushButton*>())
        button->setEnabled(true);

    this->findChild<QPushButton*>(buttonName)->setEnabled(false);
}

void MainWindow::showAboutDialog()
{
    AboutDialog* dialog = new AboutDialog(this);
    dialog->show();
}

void MainWindow::connectDevice()
{
    QObject::connect(&Connection::getInstance().getDevice(), SIGNAL(connectionStateChanged(CasparDevice&)), this, SLOT(deviceConnectionStateChanged(CasparDevice&)));
    QObject::connect(&Connection::getInstance().getDevice(), SIGNAL(versionChanged(const CasparVersion&, CasparDevice&)), this, SLOT(deviceVersionChanged(const CasparVersion&, CasparDevice&)));

    if (this->lineEditPort->text().isEmpty())
        Connection::getInstance().connect(this->lineEditName->text());
    else
        Connection::getInstance().connect(this->lineEditName->text(), this->lineEditPort->text().toInt());
}

void MainWindow::disconnectDevice()
{
    Connection::getInstance().disconnect();
}

void MainWindow::deviceConnectionStateChanged(CasparDevice& device)
{
    if (device.isConnected())
    {
        this->pushButtonConnect->setEnabled(false);
        this->pushButtonDisconnect->setEnabled(true);
        this->pushButtonRecorder->setEnabled(true);
        this->pushButtonBigFour->setEnabled(true);
        this->pushButtonSqueeze->setEnabled(true);
        this->pushButtonMixer->setEnabled(true);
        this->pushButtonDynamicGraphics->setEnabled(true);
        this->pushButtonDigitalVideoEffects->setEnabled(true);

        device.refreshVersion();
    }
    else
    {
        removeWidgets();

        statusBar()->clearMessage();

        this->pushButtonConnect->setEnabled(true);
        this->pushButtonDisconnect->setEnabled(false);
        this->pushButtonRecorder->setEnabled(false);
        this->pushButtonBigFour->setEnabled(false);
        this->pushButtonSqueeze->setEnabled(false);
        this->pushButtonMixer->setEnabled(false);
        this->pushButtonDynamicGraphics->setEnabled(false);
        this->pushButtonDigitalVideoEffects->setEnabled(false);
    }
}

void MainWindow::deviceVersionChanged(const CasparVersion& version, CasparDevice& device)
{
    statusBar()->showMessage(QString("Connected to %1 running version %2").arg(device.getName()).arg(version.getVersion()));
}

void MainWindow::showRecorder()
{
    enableDemoButton("pushButtonRecorder");
    this->frameWidgets->layout()->addWidget(new RecorderWidget(this));
}

void MainWindow::showBigFour()
{
    enableDemoButton("pushButtonBigFour");
    this->frameWidgets->layout()->addWidget(new BigFourWidget(this));
}

void MainWindow::showSqueeze()
{
    enableDemoButton("pushButtonSqueeze");
    this->frameWidgets->layout()->addWidget(new SqueezeWidget(this));
}
