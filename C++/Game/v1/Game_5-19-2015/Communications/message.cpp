#include "message.h"

message::message(const quint8 &msgtype, const QString &text, const QString &from, const cardstack &sent_cardstack)
{
    _msgtype = msgtype;
    _text = text;
    _from = from;
    _sent_cardstack = sent_cardstack;
}

// unpack a message from a QbyteArray
message::message(const QByteArray &bytes)
{
//    // data that is necessary to properly unpack
//    quint32 text_length;
//    quint8 from_length;
//    quint8 cards_count;

//    // read in unpacking info
//    QDataStream ReadStream(bytes);
//    ReadStream >> text_length;
//    ReadStream >> from_length;
//    ReadStream >> cards_count;

//    // data payload begins after unpacking info
//    quint64 cursor = sizeof(quint32) + sizeof(quint8) + sizeof(quint8);

//    // unpack the message
//    _msgtype = bytes.at(cursor);                                    cursor += 1;
//    _text = QString( bytes.mid(cursor, text_length) );              cursor += text_length;
//    _from = QString( bytes.mid(cursor, from_length) );              cursor += from_length;

//    QChar cardrank, cardsuit;

//    cardrank = bytes.at(cursor + 1) ;                               cursor += 1;
//    cardsuit = bytes.at(cursor + 1) ;                               cursor += 1;

//    _sent_cardstack.AddCard(card(cardrank, cardsuit));

    memcpy(this, bytes.data(), sizeof(bytes));

    if(_msgtype != 'P' && _msgtype != 'D' && _msgtype != 'T')
    {
        QString display_text(_text);
        display_text.replace('\n', ' ');
        qDebug() << "message(bytes) == " << _msgtype << (QChar)_msgtype << display_text << _from << _sent_cardstack.TopCard().string();
    }
}

// pack up a message into a QByteArray
QByteArray message::bytes()
{
    QByteArray bytes;

//    quint32 text_length = _text.length();
//    quint8 from_length = _from.length();
//    quint8 cards_count = _sent_cardstack.NumberOfCards();

//    QDataStream WriteStream(&bytes, QIODevice::WriteOnly);

//    // data that is necessary to properly unpack
//    WriteStream << text_length;
//    WriteStream << from_length;
//    WriteStream << cards_count;

//    // pack up the message
//    bytes.append(_msgtype);
//    bytes.append(_text);
//    bytes.append(_from);
//    bytes.append(_sent_cardstack.TopCard().string());

    memcpy(bytes.data(), this, sizeof(*this));

    qDebug() << "message::bytes(): bytes.size() == " <<  bytes.size();

    return bytes;
}

message::~message()
{
    //    qDebug() << "~message()";
}

QChar message::msgtype()
{
    return _msgtype;
}

QString message::from()
{
    return _from;
}

QString message::text()
{
    return _text;
}

cardstack message::sent_cardstack()
{
    return _sent_cardstack;
}

