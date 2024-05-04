#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "camera.h"
#include "videoitem.h"

#include <QMainWindow>

#include <QMediaPlayer>
#include <QMediaCaptureSession>

#include <QVideoSink>
#include <QVideoFrame>
#include <QGraphicsVideoItem>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void LoadVideo();
    void on_pushButton_start_pressed();
    void on_pushButton_stop_pressed();

private:
    Camera m_camera;
    QMediaPlayer m_mediaPlayer;
    QMediaCaptureSession m_capture;

    Ui::MainWindow *ui;
    QGraphicsScene m_scene;
    VideoItem* m_pVItem;
    QGraphicsVideoItem* m_pVideoItem;
};

#endif // MAINWINDOW_H
