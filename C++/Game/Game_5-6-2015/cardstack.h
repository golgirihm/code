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
    cardstack(QObject *parent = 0);
    cardstack(const card& OnlyCard, QObject *parent = 0);
    cardstack(const cardstack& other, QObject *parent = 0);
    ~cardstack();

    cardstack &operator = (const cardstack &other);

private:
    QList<card> cards;

signals:
    void StackChanged(cardstack* stack);

public slots:
    void ToStandardDeck();
    void Shuffle();

    void AddCard(const card& newCard);
    void ClearStack();
    card Look(int position);
    card TopCard();
    card TakeCard(int position);
    card TakeTopCard();

    int NumberOfCards();
    void PrintCards();
};

#endif // CARDSTACK_H
