#include <iostream>
#include "FiveOfAKindChecker.h"

bool isFiveOfAKind(const Hand& hand) {
    if (hand.cards.size() != 5) {
        return false;
    }
    for (int i = 0; i < hand.cards.size(); i++) {
        if (hand.cards[i].rank != hand.cards[0].rank) {
            return false;
        }
    }
    return true;
}

HandRank FiveOfAKindChecker::check(const Hand& hand) {
    std::cout << "Checking FIVE OF A KIND...\n";
    if (isFiveOfAKind(hand)) {
        std::cout << "Detected FIVE OF A KIND\n";
        return HandRank::FIVE_OF_A_KIND;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
