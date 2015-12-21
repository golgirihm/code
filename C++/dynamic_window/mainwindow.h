#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QList>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class myLayout;
class QPushButton;
class QTextBrowser;


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
private:
    QLabel *createLabel(const QString &text);
    myLayout *curlayout;
    QTextBrowser *centralWidget;
    QList<QPushButton *> deleteButton;

public slots:
    void deleteWidget();




};

#endif // MAINWINDOW_H
