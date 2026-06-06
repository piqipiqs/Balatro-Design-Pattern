#include <iostream>
#include "FourOfAKindChecker.h"

bool isFourOfAKind(const Hand& hand) {
    for (int i = 0; i < hand.cards.size(); i++) {
        int count = 1;
        for (int j = i + 1; j < hand.cards.size(); j++) {
            if (hand.cards[j].rank == hand.cards[i].rank) {
                count++;
            }
        }
        if (count >= 4) {
            return true;
        }
    }
    return false;
}

HandRank FourOfAKindChecker::check(const Hand& hand) {
    if (isFourOfAKind(hand)) {
        std::cout << "Detected Four of a Kind\n";
        return HandRank::FOUR_OF_A_KIND;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
