#include "Rendering/mainwindow.h"
#include <iostream>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    app.setApplicationName("CarDetector");

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
