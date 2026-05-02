#include <iostream>
#include "StraightChecker.h"
HandRank StraightChecker::check(const Hand& hand) {
    std::cout << "Checking STRAIGHT...\n";
    if (hand.value == 5) {
        std::cout << "Detected STRAIGHT\n";
        return HandRank::STRAIGHT;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}