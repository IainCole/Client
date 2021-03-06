#include "VideoTreeBaseWidget.h"

#include <QtCore/QMimeData>

#include <QtGui/QApplication>
#include <QtGui/QTreeWidgetItem>

VideoTreeBaseWidget::VideoTreeBaseWidget(QWidget* parent)
    : QTreeWidget(parent)
{
}

void VideoTreeBaseWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        dragStartPosition = event->pos();

    QTreeWidget::mousePressEvent(event);
}

void VideoTreeBaseWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (!(event->buttons() & Qt::LeftButton))
             return;

    if ((event->pos() - dragStartPosition).manhattanLength() < qApp->startDragDistance())
         return;

    QString data;
    foreach (QTreeWidgetItem* item, QTreeWidget::selectedItems())
    {
        data.append(QString("<%1>,,%2,,%3,,%4,,%5,,%6,,%7,,%8;").arg(this->objectName())
                                                                .arg(item->text(0))
                                                                .arg(item->text(1))
                                                                .arg(item->text(2))
                                                                .arg(item->text(3))
                                                                .arg(item->text(4))
                                                                .arg(item->text(5))
                                                                .arg(item->text(6)));
    }
    data.remove(data.length() - 1, 1); // Remove last index of ;

    QMimeData* mimeData = new QMimeData();
    mimeData->setData("application/library-item", data.toUtf8());

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);

    drag->exec(Qt::CopyAction);
}
