#include <iostream>
#include "FlushFiveChecker.h"

bool isFlushFive(const Hand& hand) {
    if (hand.cards.size() < 5) {
        return false;
    }

    // Check five of a kind
    for (int i = 0; i < hand.cards.size(); i++) {
        if (hand.cards[i].rank != hand.cards[0].rank) {
            return false;
        }
    }

    // Check flush
    Suit s = hand.cards[0].suit;
    for (int i = 1; i < hand.cards.size(); i++) {
        if (hand.cards[i].suit != s) {
            return false;
        }
    }

    return true;
}

HandRank FlushFiveChecker::check(const Hand& hand) {
    if (isFlushFive(hand)) {
        std::cout << "Detected Flush Five\n";
        return HandRank::FLUSH_FIVE;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
