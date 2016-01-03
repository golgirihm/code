#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new QWidget;
    centralLayout = new QGridLayout;
    sensor_1 = new sensor;
//    sensor_2 = new sensor;

    centralLayout->addWidget(sensor_1);

    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}
