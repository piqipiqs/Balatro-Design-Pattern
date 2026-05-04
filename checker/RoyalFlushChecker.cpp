#include <iostream>
#include <algorithm>
#include "RoyalFlushChecker.h"

bool isRoyalFlush(const Hand& hand) {
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

    // 10-J-Q-K-A
    std::vector<int> ranks;
    for (const Card& c : hand.cards) {
        ranks.push_back(static_cast<int>(c.rank));
    }
    std::sort(ranks.begin(), ranks.end());

    std::vector<int> royal = {
        static_cast<int>(Rank::TEN),
        static_cast<int>(Rank::JACK),
        static_cast<int>(Rank::QUEEN),
        static_cast<int>(Rank::KING),
        static_cast<int>(Rank::ACE)
    };

    return ranks == royal;
}

HandRank RoyalFlushChecker::check(const Hand& hand) {
    std::cout << "Checking ROYAL FLUSH...\n";
    if (isRoyalFlush(hand)) {
        std::cout << "Detected ROYAL FLUSH\n";
        return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
