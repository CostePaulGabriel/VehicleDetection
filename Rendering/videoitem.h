#ifndef VIDEOITEM_H
#define VIDEOITEM_H

#include <QPainter>
#include <QGraphicsVideoItem>

class VideoItem : public QGraphicsVideoItem
{
public:
    VideoItem(QGraphicsItem *parent = nullptr);
    ~VideoItem();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

};

#endif // VIDEOITEM_H
