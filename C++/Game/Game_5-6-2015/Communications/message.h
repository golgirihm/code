#ifndef MESSAGE_H
#define MESSAGE_H

#include "../card.h"
#include "../cardstack.h"

#define NO_CHAR QChar('~')
#define NO_STRING QString(NO_CHAR)

class message
{
public:
    message( const quint8 &msgtype, const QString &text = NO_STRING, const QString &from = NO_STRING, const QChar &request = NO_CHAR, const cardstack &sent_cardstack = cardstack(card()) );
    message(const QByteArray &bytes);
    ~message();

    QByteArray bytes();

    QChar msgtype();
    QChar request();
    QString from();
    QString text();
    cardstack sent_cardstack();

private:
    QChar _msgtype;
    QChar _request;
    QString _from;
    QString _text;
    cardstack _sent_cardstack;

signals:

public slots:
};

#endif // MESSAGE_H
