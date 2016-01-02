#ifndef CARDSTACK_H
#define CARDSTACK_H

#include <QObject>

#include "card.h"
class cardstack : public QObject
{
    Q_OBJECT
public:
    cardstack();
    cardstack(const card& OnlyCard);
    cardstack(const cardstack& other);
    ~cardstack();

    cardstack  &operator= (const cardstack &other);
    bool operator== (const cardstack &other);
    bool operator!= (const cardstack &other);

    friend QDataStream& operator <<(QDataStream &out, const cardstack &stack);
    friend void operator >>(QDataStream &in, cardstack &stack);

    static const quint8 SHUFFLE_SWEEPS = 2;
    static const card EMPTY_CARD;

private:
    QList<card> cards;

signals:
    void stackChanged(cardstack *stack);

public slots:
    void toStandardDeck();
    void shuffle();

    const card& look(const quint32 &position) const;
    const card &topCard() const;
    const card &bottomCard() const;

    quint32 numberOfCards() const;
    QString compressedString() const;
    void printCards() const;

    void addCard(const card &newCard);
    void addCard(const card::R_t &NewRank, const card::S_t &NewSuit);
    void clearStack();
    const card takeCard(const quint32 &position);
    const card takeTopCard();
    const card takeBottomCard();

};

#endif // CARDSTACK_H
