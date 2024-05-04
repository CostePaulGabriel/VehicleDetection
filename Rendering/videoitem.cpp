#include "videoitem.h"

VideoItem::VideoItem(QGraphicsItem *parent)
    : QGraphicsVideoItem(parent)
{

}

VideoItem::~VideoItem()
{

}

void VideoItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsVideoItem::paint(painter, option, widget);

    // Perform custom painting here
    painter->setPen(Qt::red);
    painter->drawRect(boundingRect().adjusted(10, 10, -10, -10));
}
