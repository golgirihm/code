#include "game.h"
#include "player.h"
#include "host.h"
#include "guest.h"
#include <QApplication>

#include <QThread>
#include <QDebug>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    game w;
    w.show();

    return a.exec();
}
