#include <iostream>
#include "RoyalFlushChecker.h"
HandRank RoyalFlushChecker::check(const Hand& hand) {
    std::cout << "Checking ROYAL FLUSH...\n";
    if (hand.value == 10) {
        std::cout << "Detected ROYAL FLUSH\n";
        return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}