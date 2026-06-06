#include <iostream>
#include "FlushHouseChecker.h"

bool isFlushHouse(const Hand& hand) {
    if (hand.cards.size() < 5) {
        return false;
    }

    // Check flush
    Suit s = hand.cards[0].suit;
    for (int i = 1; i < hand.cards.size(); i++) {
        if (hand.cards[i].suit != s) {
            return false;
        }
    }

    // Check full house
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

HandRank FlushHouseChecker::check(const Hand& hand) {
    if (isFlushHouse(hand)) {
        std::cout << "Detected Flush House\n";
        return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
