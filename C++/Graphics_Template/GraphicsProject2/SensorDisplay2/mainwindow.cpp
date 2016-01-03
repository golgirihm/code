#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    /// allocate all widgets and layouts that will be added to the main window
    centralWidget = new QWidget;
    centralLayout = new QGridLayout;
    sensor_1 = new sensor;
//    sensor_2 = new sensor;
//    sensor_3 = new sensor;

    /// add widgets to the central layout
    centralLayout->addWidget(sensor_1);
//    centralLayout->addWidget(sensor_2);
//    centralLayout->addWidget(sensor_3, 0,1,2,1);

    /// apply the central layout with all added widgets to the central widget,
    /// and officially set this as the central widget for the main window
    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}
