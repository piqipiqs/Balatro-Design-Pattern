#include <iostream>
#include "FullHouseChecker.h"

bool isFullHouse(const Hand& hand) {
    bool hasThree = false;
    bool hasPair = false;
    for (int i = 0; i < hand.cards.size(); i++) {
        int count = 0;
        for (int j = 0; j < hand.cards.size(); j++) {
            if (hand.cards[j].rank == hand.cards[i].rank) {
                count++;
            }
        }
        if (count == 3) {
            hasThree = true;
        }
        if (count == 2) {
            hasPair = true;
        }
    }
    return hasThree && hasPair;
}

HandRank FullHouseChecker::check(const Hand& hand) {
    if (isFullHouse(hand)) {
        std::cout << "Detected Full House\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
