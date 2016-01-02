#include "message.h"

#include <QDebug>

message::message(const QChar &newMsgtype, const QChar &newSenderID, const QString &newText, const QByteArray &newExtraData, const cardstack &newCards)
{
    _msgtype = newMsgtype.toLatin1();
    _senderID = newSenderID.toLatin1();
    _text = newText;
    _extraData = newExtraData;
    _cards = newCards;

    // stream _msgtype, _text, _from, and _cards into (this)
    QDataStream stream(this, QIODevice::WriteOnly);

    stream << _msgtype;
    stream << _senderID;
    stream << _text.toLatin1(); // toLatin1() here saves space for sending over network
    stream << _extraData;
    stream << _cards;

}

// unpack a message from a QbyteArray
message::message(const QByteArray &bytes)
{
    QDataStream stream(bytes);
    char* Latin1_text;

    stream >> _msgtype;
    stream >> _senderID;
    stream >> Latin1_text;          _text = QString::fromLatin1(Latin1_text);
    stream >> _extraData;
    stream >> _cards;

    append(bytes);
}

// pack up a message into a QByteArray
QByteArray message::bytes()
{
//    qDebug() << "message::bytes(): bytes.size() == " <<  bytes.size();

    return (QByteArray)(*this);
}

message::~message()
{
    //    qDebug() << "~message()";
}

const quint8 &message::msgtype() const
{
    return _msgtype;
}

const quint8 &message::senderID() const
{
    return _senderID;
}

const QString &message::text() const
{
    return _text;
}

const QByteArray &message::extraData() const
{
    return _extraData;
}

const cardstack &message::cards() const
{
    return _cards;
}

QString message::compressedString() const
{
    return QChar(msgtype()) + ',' + QString::number(senderID()) + ',' + text() + ',' + QString(extraData()) + ',' + cards().compressedString();
}
