#include <iostream>
#include "FlushFiveChecker.h"
HandRank FlushFiveChecker::check(const Hand& hand) {
    std::cout << "Checking FLUSH FIVE...\n";
    if (hand.value == 13) {
        std::cout << "Detected FLUSH FIVE\n";
        return HandRank::FLUSH_FIVE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}