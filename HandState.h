#ifndef HANDSTATE_H
#define HANDSTATE_H

#include <vector>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

class HandState {
public:
    static const int MAX_CARDS = 8;
    static const int MAX_SELECT = 5;

    void refill(Deck& deck);
    Hand getSelectedHand(const std::vector<int>& indices) const;
    void removeCards(const std::vector<int>& indices);

    const std::vector<Card>& getCards() const;
    int size() const;

private:
    std::vector<Card> cards;
};

#endif
