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

HandRank FlushChecker::check(const Hand& hand) {
    std::cout << "Checking FLUSH...\n";
    if (isFlush(hand)) {
        std::cout << "Detected FLUSH\n";
        return HandRank::FLUSH;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
