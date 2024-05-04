#ifndef VIDEOSCENE_H
#define VIDEOSCENE_H

#include <QObject>

class VideoAnalizer : public QObject
{
    Q_OBJECT

public:
    explicit VideoAnalizer(QWidget *pParent = nullptr);
    ~VideoAnalizer();

private:

};

#endif // VIDEOSCENE_H
