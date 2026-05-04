#ifndef CARD_H
#define CARD_H

enum class Suit {
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS
};

enum class Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card {
    Rank rank;
    Suit suit;
};

#endif
