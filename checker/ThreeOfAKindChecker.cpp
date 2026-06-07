#include <iostream>
#include "ThreeOfAKindChecker.h"

std::vector<Card> getThreeOfAKindCards(const Hand& hand) {
    for (int i = 0; i < hand.cards.size(); i++) {
        int count = 0;
        std::vector<Card> scoring;
        for (int j = 0; j < hand.cards.size(); j++) {
            if (hand.cards[j].rank == hand.cards[i].rank) {
                count++;
                scoring.push_back(hand.cards[j]);
            }
        }
        if (count == 3) {
            return scoring;
        }
    }
    return {};
}

ScoreResult ThreeOfAKindChecker::check(const Hand& hand) {
    std::vector<Card> scoring = getThreeOfAKindCards(hand);
    if (!scoring.empty()) {
        std::cout << "Detected Three of a Kind\n";
        return { HandRank::THREE_OF_A_KIND, 0, 0.0f, scoring };
    }
    if (nextChecker) return nextChecker->check(hand);
    return { HandRank::HIGH_CARD, 0, 0.0f, {} };
}
