#ifndef MESSAGE_H
#define MESSAGE_H

#include "card.h"
#include "cardstack.h"

#define NO_CHAR QChar('~')
#define NO_STRING QString(NO_CHAR)

class message : public QByteArray
{
public:
    message(const quint8 &newMsgtype, const QString &newText = NO_STRING, const QString &newFrom = NO_STRING, const cardstack &newCards = cardstack(card()) );
    message(const QByteArray &bytes);
    ~message();

    QByteArray bytes();

    QChar &msgtype();
    QString &from();
    QString &text();
    cardstack &cards();
    QString compressedString();

private:
    QChar _msgtype;
    QString _from;
    QString _text;
    cardstack _cards;

signals:

public slots:
};

#endif // MESSAGE_H
