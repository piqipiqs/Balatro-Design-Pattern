#include <iostream>
#include "TwoPairChecker.h"
HandRank TwoPairChecker::check(const Hand& hand) {
    std::cout << "Checking TWO PAIR...\n";
    if (hand.value == 3) {
        std::cout << "Detected TWO PAIR\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}