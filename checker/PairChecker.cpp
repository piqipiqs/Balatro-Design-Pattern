#include <iostream>
#include "PairChecker.h"
HandRank PairChecker::check(const Hand& hand) {
    std::cout << "Checking PAIR...\n";
    if (hand.value == 2) {
        std::cout << "Detected PAIR\n";
        return HandRank::PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}