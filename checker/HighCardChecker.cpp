#include <iostream>
#include "HighCardChecker.h"

std::vector<Card> getHighCard(const Hand& hand) {
    if (hand.cards.empty()) return {};
    Card highest = hand.cards[0];
    for (const Card& c : hand.cards) {
        if (static_cast<int>(c.rank) > static_cast<int>(highest.rank)) {
            highest = c;
        }
    }
    return { highest };
}

ScoreResult HighCardChecker::check(const Hand& hand) {
    std::vector<Card> scoring = getHighCard(hand);
    if (!scoring.empty()) {
        std::cout << "Detected High Card\n";
        return { HandRank::HIGH_CARD, 0, 0.0f, scoring };
    }
    if (nextChecker) return nextChecker->check(hand);
    return { HandRank::HIGH_CARD, 0, 0.0f, {} };
}
