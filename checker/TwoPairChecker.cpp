#include <iostream>
#include <algorithm>
#include "TwoPairChecker.h"

std::vector<Card> getTwoPairCards(const Hand& hand) {
    std::vector<Rank> counted;
    std::vector<Card> scoring;
    int pairCount = 0;

    for (int i = 0; i < hand.cards.size(); i++) {
        Rank r = hand.cards[i].rank;
        if (std::find(counted.begin(), counted.end(), r) != counted.end()) continue;

        int count = 0;
        for (int j = 0; j < hand.cards.size(); j++) {
            if (hand.cards[j].rank == r) {
                count++;
                if (count <= 2) {
                    scoring.push_back(hand.cards[j]);
                }
            }
        }

        if (count >= 2) {
            pairCount++;
            counted.push_back(r);
        } else {
            while(count > 0) {
                scoring.pop_back();
                count--;
            }
        }

        if (pairCount == 2) {
            return scoring;
        }
    }
    return {};
}

ScoreResult TwoPairChecker::check(const Hand& hand) {
    std::vector<Card> scoring = getTwoPairCards(hand);
    if (!scoring.empty()) {
        std::cout << "Detected Two Pair\n";
        return { HandRank::TWO_PAIR, 0, 0.0f, scoring };
    }
    if (nextChecker) return nextChecker->check(hand);
    return { HandRank::HIGH_CARD, 0, 0.0f, {} };
}
