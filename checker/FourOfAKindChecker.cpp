#include <iostream>
#include "FourOfAKindChecker.h"
HandRank FourOfAKindChecker::check(const Hand& hand) {
    std::cout << "Checking FOUR OF A KIND...\n";
    if (hand.value == 8) {
        std::cout << "Detected FOUR OF A KIND\n";
        return HandRank::FOUR_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}