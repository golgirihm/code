#include "message.h"

message::message(QChar msgtype, QString text, QString from, QChar request)
{
    _msgtype = msgtype;
    _text = text;
    _from = from;
    _request = request;
}

message::message(QChar msgtype, QString text, QString from)
{
    _msgtype = msgtype;
    _text = text;
    _from = from;
    _request = NONE;
}

message::message(QChar msgtype, QString text)
{
    _msgtype = msgtype;
    _text = text;
    _from = QString();
    _request = NONE;
}

message::message(QChar msgtype)
{
    _msgtype = msgtype;
    _text = QString();
    _from = QString();
    _request = NONE;
}

message::message(QByteArray bytes)
{
//    qDebug() << endl << "start of message(QbyteArray bytes) constructor: " << QString(bytes);

    QDataStream stream(bytes);

    stream >> _msgtype;
    stream >> _text;
    stream >> _request;
    stream >> _from;

//    qDebug() << endl << "end of message(QbyteArray bytes) constructor: " << this->msgtype() << this->text() << this->from() << this->request();
}

message::~message()
{
}

QChar message::msgtype()
{
    return _msgtype;
}

QChar message::request()
{
    return _request;
}

QString message::from()
{
    return _from;
}

QString message::text()
{
    return _text;
}

QByteArray message::bytes()
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::WriteOnly);

    stream << _msgtype;
    stream << _text;
    stream << _request;
    stream << _from;

//    qDebug() << "in bytes(): buffer.size() == " <<  buffer.size();

    return buffer;
}

