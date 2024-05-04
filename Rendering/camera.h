#pragma once

#include <QObject>
#include <QMap>
#include <QCamera>
#include <QCameraDevice>

class Camera : public QObject
{
    Q_OBJECT

public:
    Camera(QObject *parent = nullptr);
    ~Camera();

public:
    void Start();
    void Stop();
    QCamera *GetCamera();

private:
    int m_deviceId;
    QString m_deviceName;
    QCamera m_camera;
};
