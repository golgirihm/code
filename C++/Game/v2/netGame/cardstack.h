#ifndef CARDSTACK_H
#define CARDSTACK_H

#include <QObject>
#include <QWidget>

#include "card.h"

namespace RandShuf {
    static const int SWEEPS = 2;
}

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

private:
    QList<card> cards;

signals:
    void StackChanged(cardstack* stack);

public slots:
    void ToStandardDeck();
    void Shuffle();

    void AddCard(const card& newCard);
    void AddCard(const QChar& NewRank, const QChar& NewSuit);
    void ClearStack();
    card Look(int position) const;
    card TopCard() const;
    card BottomCard() const;
    card TakeCard(int position);
    card TakeTopCard();
    card TakeBottomCard();

    int NumberOfCards() const;
    QString CompressedString() const;
    void PrintCards() const;
};

#endif // CARDSTACK_H
