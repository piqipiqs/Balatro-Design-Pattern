#include <iostream>
#include "ThreeOfAKindChecker.h"
HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    std::cout << "Checking THREE OF A KIND...\n";
    if (hand.value == 4) {
        std::cout << "Detected THREE OF A KIND\n";
        return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}