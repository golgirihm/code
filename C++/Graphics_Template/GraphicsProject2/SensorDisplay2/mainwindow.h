#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sensor.h"
#include <QMainWindow>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWidget *centralWidget;
    QGridLayout *centralLayout;
    sensor *sensor_1;
//    sensor *sensor_2;
//    sensor *sensor_3;

};

#endif // MAINWINDOW_H
