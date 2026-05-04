#include <iostream>
#include <algorithm>
#include "StraightFlushChecker.h"

bool isStraightFlush(const Hand& hand) {
    if (hand.cards.size() < 5) {
        return false;
    }

    // Check flush
    Suit s = hand.cards[0].suit;
    for (int i = 1; i < hand.cards.size(); i++) {
        if (hand.cards[i].suit != s) {
            return false;
        }
    }

    // Check straight
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

HandRank StraightFlushChecker::check(const Hand& hand) {
    std::cout << "Checking STRAIGHT FLUSH...\n";
    if (isStraightFlush(hand)) {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
