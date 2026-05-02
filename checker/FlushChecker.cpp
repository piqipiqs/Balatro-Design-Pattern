#include <iostream>
#include "FlushChecker.h"
HandRank FlushChecker::check(const Hand& hand) {
    std::cout << "Checking FLUSH...\n";
    if (hand.value == 6) {
        std::cout << "Detected FLUSH\n";
        return HandRank::FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}