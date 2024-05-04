#include "camera.h"
#include <QMediaDevices>

Camera::Camera(QObject *parent) :
    QObject(parent)
{
    for(const QCameraDevice& cameraDevice : QMediaDevices::videoInputs()) {
        qDebug() << cameraDevice.description();
        m_camera.setCameraDevice(cameraDevice);
    }
}

Camera::~Camera()
{
    m_camera.stop();
}

void Camera::Start()
{
    m_camera.start();
}

void Camera::Stop()
{
    m_camera.stop();
}

QCamera *Camera::GetCamera()
{
    return &m_camera;
}
