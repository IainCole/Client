#include "MainWindow.h"
#include "AboutDialog.h"
#include "Enum.h"
#include "StatusbarEvent.h"
#include "SqueezeWidget.h"
#include "StartWidget.h"

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

    showStart();

    qApp->installEventFilter(this);
}

void MainWindow::setupUiMenu()
{
     QMenu* fileMenu = new QMenu(this);
     fileMenu->addAction("&Open", this, SLOT(closeWindow()), QKeySequence::fromString("Ctrl+O"));
     fileMenu->addSeparator();
     fileMenu->addAction("&Quit", this, SLOT(closeWindow()), QKeySequence::fromString("Ctrl+Q"));

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

void MainWindow::enableDemoButton(const QString& buttonName)
{
    while(!this->frameWidgets->layout()->isEmpty())
        delete this->frameWidgets->layout()->takeAt(0)->widget();

    foreach(QPushButton* button, this->findChildren<QPushButton*>())
        button->setEnabled(true);

    this->findChild<QPushButton*>(buttonName)->setEnabled(false);
}

void MainWindow::showAboutDialog()
{
    AboutDialog* dialog = new AboutDialog(this);
    dialog->show();
}

void MainWindow::showStart()
{
    enableDemoButton("pushButtonStart");
    this->frameWidgets->layout()->addWidget(new StartWidget(this));
}

void MainWindow::showSqueeze()
{
    enableDemoButton("pushButtonSqueeze");
    this->frameWidgets->layout()->addWidget(new SqueezeWidget(this));
}
