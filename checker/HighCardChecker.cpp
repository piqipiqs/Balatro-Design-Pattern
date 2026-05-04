#include <iostream>
#include "HighCardChecker.h"

bool isHighCard(const Hand& hand) {
    return !hand.cards.empty();
}

HandRank HighCardChecker::check(const Hand& hand) {
    std::cout << "Checking HIGH CARD...\n";
    if (isHighCard(hand)) {
        std::cout << "Detected HIGH CARD\n";
        return HandRank::HIGH_CARD;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
