#include "player.h"
#include <QApplication>

#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    player w;
    w.show();


    return a.exec();
}
