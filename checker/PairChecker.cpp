#include <iostream>
#include "PairChecker.h"

bool isPair(const Hand& hand) {
    for (int i = 0; i < hand.cards.size(); i++) {
        for (int j = i + 1; j < hand.cards.size(); j++) {
            if (hand.cards[i].rank == hand.cards[j].rank) {
                return true;
            }
        }
    }
    return false;
}

HandRank PairChecker::check(const Hand& hand) {
    if (isPair(hand)) {
        std::cout << "Detected Pair\n";
        return HandRank::PAIR;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
