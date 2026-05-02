#include <iostream>
#include "FullHouseChecker.h"
HandRank FullHouseChecker::check(const Hand& hand) {
    std::cout << "Checking FULL HOUSE...\n";
    if (hand.value == 7) {
        std::cout << "Detected FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}