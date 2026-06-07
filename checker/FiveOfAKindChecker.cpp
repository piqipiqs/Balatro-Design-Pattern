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

ScoreResult FiveOfAKindChecker::check(const Hand& hand) {
    if (isFiveOfAKind(hand)) {
        std::cout << "Detected Five of a Kind\n";
        return { HandRank::FIVE_OF_A_KIND, 0, 0.0f, hand.cards };
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return { HandRank::HIGH_CARD, 0, 0.0f, {} };
}
