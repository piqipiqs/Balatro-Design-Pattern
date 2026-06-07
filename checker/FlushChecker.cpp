#include <iostream>
#include "FlushChecker.h"

bool isFlush(const Hand& hand) {
    if (hand.cards.size() < 5) {
        return false;
    }
    Suit s = hand.cards[0].suit;
    for (int i = 1; i < hand.cards.size(); i++) {
        if (hand.cards[i].suit != s) {
            return false;
        }
    }
    return true;
}

ScoreResult FlushChecker::check(const Hand& hand) {
    if (isFlush(hand)) {
        std::cout << "Detected Flush\n";
        return { HandRank::FLUSH, 0, 0.0f, hand.cards };
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return { HandRank::HIGH_CARD, 0, 0.0f, {} };
}
