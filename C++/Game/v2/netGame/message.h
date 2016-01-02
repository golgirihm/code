#ifndef MESSAGE_H
#define MESSAGE_H

#include "card.h"
#include "cardstack.h"

#define NO_STRING ""

class message : public QByteArray
{
public:
    message(const QChar &newMsgtype,
            const QChar &newSenderID,
            const QString &newText = NO_STRING,
            const QByteArray &newExtraData = NO_STRING,
            const cardstack &newCards = cardstack(card()));
    message(const QByteArray &bytes);
    ~message();

    QByteArray bytes();

    const quint8 &msgtype() const;
    const quint8 &senderID() const;
    const QByteArray &extraData() const;
    const QString &text()const;
    const cardstack &cards() const;
    QString compressedString() const;

private:
    quint8 _msgtype;
    quint8 _senderID;
    QString _text;
    QByteArray _extraData;
    cardstack _cards;

signals:

public slots:
};

#endif // MESSAGE_H
