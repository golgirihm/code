#include "message.h"

#include <QDebug>

message::message(const quint8 &newMsgtype, const QString &newText, const QString &newFrom, const cardstack &newCards)
{
    _msgtype = newMsgtype;
    _text = newText;
    _from = newFrom;
    _cards = newCards;

    // convert _msgtype, _text, _from, and _cards into a QByteArray,
    // then use the inherited append() function
    append(bytes());

}

// unpack a message from a QbyteArray
message::message(const QByteArray &bytes)
{
    QDataStream stream(bytes);
    char* Latin1_text;
    char* Latin1_from;

    stream >> _msgtype;
    stream >> Latin1_text;         _text = QString::fromLatin1(Latin1_text);
    stream >> Latin1_from;         _from = QString::fromLatin1(Latin1_from);
    stream >> _cards;

    // don't clutter the debug output
    if(_msgtype != 'P' && _msgtype != 'D' && _msgtype != 'T')
    {
        QString display_text(_text);
        display_text.replace('\n', ' ');
//        qDebug() << "message(bytes) == " << _msgtype << (QChar)_msgtype << display_text << from << _cards.compressedString();
    }

}

// pack up a message into a QByteArray
QByteArray message::bytes()
{
    QByteArray bytes;

    QDataStream stream(&bytes, QIODevice::WriteOnly);

    stream << _msgtype;
    stream << _text.toLatin1();
    stream << _from.toLatin1();
    stream << _cards;

//    qDebug() << "message::bytes(): bytes.size() == " <<  bytes.size();

    return bytes;
}

message::~message()
{
    //    qDebug() << "~message()";
}

QChar &message::msgtype()
{
    return _msgtype;
}

QString &message::from()
{
    return _from;
}

QString &message::text()
{
    return _text;
}

cardstack &message::cards()
{
    return _cards;
}

QString message::compressedString()
{
    return msgtype() + ',' + text() + ',' + from() + ',' + cards().compressedString();
}

