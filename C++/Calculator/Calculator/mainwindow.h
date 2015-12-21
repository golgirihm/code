#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "global.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QElapsedTimer>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void processButtonClick(QAbstractButton *clickedButton);

    void setlast_QLineEdit();

    void perform_calculation();

signals:
    void NeedToCalculate();

private:
    Ui::MainWindow *ui;
    QList<QLineEdit*> CalcLineEdits;

    QString prev_ans;
    QLineEdit* last_QLineEdit;
    QRadioButton* last_QRadioButton;

    // for optimization testing
    double totaltimes[ITERATIONS];
    double subtimes[ITERATIONS];
    QElapsedTimer maintimer;
    QElapsedTimer subtimer;

};

#endif // MAINWINDOW_H
