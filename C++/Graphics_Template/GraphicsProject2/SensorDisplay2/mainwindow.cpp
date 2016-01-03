#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new QWidget;
    layout = new QGridLayout;
    sensor_1 = new sensor;
//    sensor_2 = new sensor;

    layout->addWidget(sensor_1);
//    layout->addWidget(sensor_2,0,1);


    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}
