#ifndef CARD_H
#define CARD_H

#include <QDebug>

class card
{
public:
    // standard card suits
    enum S_t : char
    {
        SPADES = 'S',
        DIAMONDS = 'D',
        CLUBS = 'C',
        HEARTS = 'H',
        NO_SUIT = 'Z'
    };

    // standard card ranks
    enum R_t : char
    {
        ACE = 'A',
        TWO = '2',
        THREE = '3',
        FOUR = '4',
        FIVE = '5',
        SIX = '6',
        SEVEN = '7',
        EIGHT = '8',
        NINE = '9',
        TEN = 'T',
        JACK = 'J',
        QUEEN = 'Q',
        KING = 'K',
        NO_RANK = 'Z'
    };

public:
    card();
    card(R_t NewRank, S_t NewSuit);
    ~card();

    card &operator= (const card &other);
    bool operator== (const card &other) const;
    bool operator!= (const card &other) const;

private:
    R_t rank;
    S_t suit;

signals:

public slots:
    void setRank(R_t NewRank);
    void setSuit(S_t NewSuit);
    void setCard(R_t NewRank, S_t NewSuit);
    const S_t &getSuit() const;
    const R_t &getRank() const;
    QString compressedString() const;
};

const card::S_t SUITS_STD[] = { card::SPADES,
                                card::DIAMONDS,
                                card::CLUBS,
                                card::HEARTS };
const quint8 NUMSUITS_STD = ((quint8)(sizeof(SUITS_STD) / sizeof(*SUITS_STD)));

const card::R_t RANKS_STD[] = { card::ACE,
                                card::TWO,
                                card::THREE,
                                card::FOUR,
                                card::FIVE,
                                card::SIX,
                                card::SEVEN,
                                card::EIGHT,
                                card::NINE,
                                card::TEN,
                                card::JACK,
                                card::QUEEN,
                                card::KING };
const quint8 NUMRANKS_STD = ((quint8)(sizeof(RANKS_STD) / sizeof(*RANKS_STD)));


#endif // CARD_H
