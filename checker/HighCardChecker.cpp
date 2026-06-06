#include <iostream>
#include "HighCardChecker.h"

bool isHighCard(const Hand& hand) {
    return !hand.cards.empty();
}

HandRank HighCardChecker::check(const Hand& hand) {
    if (isHighCard(hand)) {
        std::cout << "Detected High Card\n";
        return HandRank::HIGH_CARD;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
