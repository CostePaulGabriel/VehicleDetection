#include "mainwindow.h"
#include "ui_mainwindow.h"

// https://forum.qt.io/topic/96498/fitting-qgraphicsvideoitem-and-qgraphicsscene-to-qgraphicsview/5
// https://forum.qt.io/topic/141042/drawing-overlay-on-qvideowidget-5-15-2
// https://stackoverflow.com/questions/71894119/widgets-and-painter-is-getting-overlayed-by-qvideowidget

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView_video->setFrameStyle(false);
    ui->graphicsView_video->setScene(&m_scene);

    QObject::connect(ui->action_loadVideo, &QAction::triggered, this, &MainWindow::LoadVideo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_pressed()
{
    if(m_camera.GetCamera()->isActive()) {
        m_camera.Stop();
    }
    m_pVItem = new VideoItem;

    m_camera.Start();
    m_capture.setCamera(m_camera.GetCamera());
    m_capture.setVideoOutput(m_pVItem);
    m_pVItem->setSize(ui->graphicsView_video->viewport()->size());
    m_scene.addItem(m_pVItem);
    ui->graphicsView_video->fitInView(m_pVItem, Qt::KeepAspectRatio);
}

void MainWindow::on_pushButton_stop_pressed()
{
    if(m_camera.GetCamera()->isActive()) {
        m_camera.Stop();
    }
    m_mediaPlayer.stop();
    m_scene.clear();
}

void MainWindow::LoadVideo()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, tr("Open Video File"), QString(), tr("Video Files (*.mp4)"));
    if (!filePath.isEmpty()) {
        m_mediaPlayer.setSource(QUrl::fromLocalFile(filePath));
        m_pVideoItem = new QGraphicsVideoItem;
        m_mediaPlayer.setVideoOutput(m_pVideoItem);
        m_pVideoItem->setSize(ui->graphicsView_video->viewport()->size());
        m_mediaPlayer.play();

        m_scene.addItem(m_pVideoItem);
        ui->graphicsView_video->fitInView(m_pVideoItem, Qt::IgnoreAspectRatio);
    }
}
