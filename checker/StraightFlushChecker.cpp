#include <iostream>
#include "StraightFlushChecker.h"
HandRank StraightFlushChecker::check(const Hand& hand) {
    std::cout << "Checking STRAIGHT FLUSH...\n";
    if (hand.value == 9) {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}