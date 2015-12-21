#include "mylayout.h"
#include "mainwindow.h"
#include <QTextBrowser>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow()
{
    curlayout = new myLayout;


    centralWidget = new QTextBrowser;
    centralWidget->setPlainText("This is the central widget.");


    for(int i = 0; i < 40; ++i)
    {
        myLayout::Position newposition = (myLayout::Position) (i % 5);

        QPushButton *newbutton = new QPushButton("Delete Widget [" + QString::number(i) + "]");
        deleteButton.append(newbutton);
        connect(deleteButton[i], &QPushButton::clicked, this, &MainWindow::deleteWidget );
        curlayout->addWidget(deleteButton[i], newposition);
    }

    curlayout->addWidget(centralWidget, myLayout::Center);
    curlayout->addWidget(createLabel("North widget"), myLayout::North);
    setLayout(curlayout);




//        QLayoutItem *item;
//        while ((item = curlayout->takeAt(0)) != 0)
//        {
//            delete item;
//        }

//    delete this->layout();

//    curlayout = new myLayout;
//    curlayout->addWidget(createLabel("South widget"), myLayout::South);
//    setLayout(curlayout);


}

QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    return label;
}

void MainWindow::deleteWidget()
{

    QObject* obj = sender();

    qDebug() << "deleting a widget";
//    curlayout->removeWidget(centralWidget);
    curlayout->removeWidget(obj);
//    deleteButton.removeAt(num);
//    curlayout->addWidget(createLabel("North widget"), myLayout::North);

}
