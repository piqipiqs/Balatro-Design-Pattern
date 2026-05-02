#include <iostream>
#include "FlushHouseChecker.h"
HandRank FlushHouseChecker::check(const Hand& hand) {
    std::cout << "Checking FLUSH HOUSE...\n";
    if (hand.value == 12) {
        std::cout << "Detected FLUSH HOUSE\n";
        return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}