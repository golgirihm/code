#ifndef MESSAGE_H
#define MESSAGE_H

#include "card.h"
#include "cardstack.h"

#define NO_CHAR QChar('~')
#define NO_STRING QString(NO_CHAR)

class message
{
public:
    message(const quint8 &newMsgtype, const QString &newText = NO_STRING, const QString &newFrom = NO_STRING, const cardstack &newCards = cardstack(card()) );
    message(const QByteArray &bytes);
    ~message();

    QByteArray bytes();

    QChar get_msgtype();
    QString get_from();
    QString get_text();
    cardstack get_cards();

private:
    quint8 msgtype;
    QString from;
    QString text;
    cardstack cards;

signals:

public slots:
};

#endif // MESSAGE_H
