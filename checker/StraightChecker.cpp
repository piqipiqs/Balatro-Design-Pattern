#include <iostream>
#include <algorithm>
#include "StraightChecker.h"

bool isStraight(const Hand& hand) {
    if (hand.cards.size() < 5) {
        return false;
    }
    std::vector<int> ranks;
    for (const Card& c : hand.cards) {
        ranks.push_back(static_cast<int>(c.rank));
    }
    std::sort(ranks.begin(), ranks.end());

    bool straight = true;
    for (int i = 1; i < ranks.size(); i++) {
        if (ranks[i] != ranks[i - 1] + 1) {
            straight = false;
            break;
        }
    }

    // Ace-low straight: A-2-3-4-5
    if (!straight && ranks.back() == static_cast<int>(Rank::ACE)) {
        std::vector<int> aceLow = {2, 3, 4, 5, 14};
        straight = (ranks == aceLow);
    }
    return straight;
}

ScoreResult StraightChecker::check(const Hand& hand) {
    if (isStraight(hand)) {
        std::cout << "Detected Straight\n";
        return { HandRank::STRAIGHT, 0, 0.0f, hand.cards };
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return { HandRank::HIGH_CARD, 0, 0.0f, {} };
}
