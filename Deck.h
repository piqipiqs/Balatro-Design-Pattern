#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();

    std::vector<Card> draw(int n);
    int remaining() const;

private:
    std::vector<Card> cards;

    void initialize();
    void shuffle();
};

#endif
