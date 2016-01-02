#include "gameUI.h"
#include <QApplication>

#include <QThread>
#include <QDebug>

// TODO: REMOVE
#include "message.h"
#include "cardstack.h"
#include "card.h"
#include "player.h"
//#include "host.h"
//#include "guest.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    gameUI game1;
    game1.show();

    // why does this work, but not when it gets sent?
//    qDebug() << QString(QByteArray().append(5));


//    cardstack hand1;
//    hand1.toStandardDeck();
//    message msg1(C::CHATMESSAGE, 64, "SomeText", "SomeExtraData", hand1);
//    message msg2((QByteArray)msg1);
//    qDebug() << msg2.compressedString();

//    cardstack hand2;
//    hand2 = msg2.cards();
//    hand2.printCards();


    return a.exec();
//return 0;
}
