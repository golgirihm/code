#include "gameUI.h"
#include "player.h"
#include "host.h"
#include "guest.h"
#include <QApplication>

#include <QThread>
#include <QDebug>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    gameUI game1;
    game1.show();

    return a.exec();
}
