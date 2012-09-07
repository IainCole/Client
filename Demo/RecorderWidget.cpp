#include "RecorderWidget.h"
#include "StatusbarEvent.h"

#include <QtCore/QTime>
#include <QtCore/QTimer>

RecorderWidget::RecorderWidget(QWidget* parent) : QWidget(parent)
{
    setupUi(this);

    StatusbarEvent* event = new StatusbarEvent("Loading record demo");
    qApp->postEvent(qApp, event);

    this->lcdNumber->hide();

    QTimer* timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(40);
}

bool RecorderWidget::eventFilter(QObject* target, QEvent* event)
{
    //if(event->type() == static_cast<QEvent::Type>(EventEnum::Statusbar))
    //{
    //    StatusbarEvent* statusbarEvent = static_cast<StatusbarEvent*>(event);
    //    statusBar()->showMessage(statusbarEvent->getMessage(), 5000);
    //}

    return QObject::eventFilter(target, event);
}

void RecorderWidget::updateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss").append(":");

    int frame = time.msec() / 40;
    if(frame < 10)
        text.append("0");

    text.append(QString("%1").arg(frame));

    this->lcdNumber->display(text);
    if(this->lcdNumber->isHidden())
        this->lcdNumber->show();
}

void RecorderWidget::buttonPressed()
{

}
