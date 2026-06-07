#include <iostream>
#include "PairChecker.h"

std::vector<Card> getPairCards(const Hand& hand) {
    for (int i = 0; i < hand.cards.size(); i++) {
        for (int j = i + 1; j < hand.cards.size(); j++) {
            if (hand.cards[i].rank == hand.cards[j].rank) {
                return { hand.cards[i], hand.cards[j] };
            }
        }
    }
    return {};
}

ScoreResult PairChecker::check(const Hand& hand) {
    std::vector<Card> scoring = getPairCards(hand);
    if (!scoring.empty()) {
        std::cout << "Detected Pair\n";
        return { HandRank::PAIR, 0, 0.0f, scoring };
    }
    if (nextChecker) return nextChecker->check(hand);
    return { HandRank::HIGH_CARD, 0, 0.0f, {} };
}
