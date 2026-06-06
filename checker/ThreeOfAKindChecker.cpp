#include <iostream>
#include "ThreeOfAKindChecker.h"

bool isThreeOfAKind(const Hand& hand) {
    for (int i = 0; i < hand.cards.size(); i++) {
        int count = 1;
        for (int j = i + 1; j < hand.cards.size(); j++) {
            if (hand.cards[j].rank == hand.cards[i].rank) {
                count++;
            }
        }
        if (count >= 3) {
            return true;
        }
    }
    return false;
}

HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    if (isThreeOfAKind(hand)) {
        std::cout << "Detected Three of a Kind\n";
        return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
