#include "message.h"
#include <QLatin1String>

message::message(const quint8 &newMsgtype, const QString &newText, const QString &newFrom, const cardstack &newCards)
{
    msgtype = newMsgtype;
    text = newText;
    from = newFrom;
    cards = newCards;
}

// unpack a message from a QbyteArray
message::message(const QByteArray &bytes)
{
    QDataStream stream(bytes);
    char* Latin1_text;
    char* Latin1_from;

    stream >> msgtype;
    stream >> Latin1_text;         text = QString::fromLatin1(Latin1_text);
    stream >> Latin1_from;         from = QString::fromLatin1(Latin1_from);
    stream >> cards;

    // don't clutter the debug output
    if(msgtype != 'P' && msgtype != 'D' && msgtype != 'T')
    {
        QString display_text(text);
        display_text.replace('\n', ' ');
        qDebug() << "message(bytes) == " << msgtype << (QChar)msgtype << display_text << from << cards.compressedString();
    }

}

// pack up a message into a QByteArray
QByteArray message::bytes()
{
    QByteArray bytes;

    QDataStream stream(&bytes, QIODevice::WriteOnly);

    stream << msgtype;
    stream << text.toLatin1();
    stream << from.toLatin1();
    stream << cards;

//    qDebug() << "message::bytes(): bytes.size() == " <<  bytes.size();

    return bytes;
}

message::~message()
{
    //    qDebug() << "~message()";
}

QChar message::get_msgtype()
{
    return msgtype;
}

QString message::get_from()
{
    return from;
}

QString message::get_text()
{
    return text;
}

cardstack message::get_cards()
{
    return cards;
}

