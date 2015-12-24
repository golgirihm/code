#ifndef CARDSTACK_H
#define CARDSTACK_H

#include <QObject>
#include <QWidget>

#include "card.h"

class cardstack : public QObject
{
    Q_OBJECT
public:
    cardstack();
    cardstack(const card& OnlyCard);
    cardstack(const cardstack& other);
    ~cardstack();

    cardstack &operator = (const cardstack &other);
    friend QDataStream& operator <<(QDataStream &out, const cardstack &stack);
    friend void operator >>(QDataStream &in, cardstack &stack);

    static const quint8 SHUFFLE_SWEEPS = 2;

private:
    QList<card> cards;

signals:
    void stackChanged(cardstack* stack);

public slots:
    void toStandardDeck();
    void shuffle();

    void addCard(const card& newCard);
    void addCard(const QChar& NewRank, const QChar& NewSuit);
    void clearStack();
    card look(int position) const;
    card topCard() const;
    card bottomCard() const;
    card takeCard(int position);
    card takeTopCard();
    card takeBottomCard();

    int numberOfCards() const;
    QString compressedString() const;
    void printCards() const;
};

#endif // CARDSTACK_H
