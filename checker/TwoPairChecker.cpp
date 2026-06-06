#include <iostream>
#include <algorithm>
#include "TwoPairChecker.h"

bool isTwoPair(const Hand& hand) {
    int pairsFound = 0;
    std::vector<Rank> counted;
    for (int i = 0; i < hand.cards.size(); i++) {
        Rank r = hand.cards[i].rank;
        if (std::find(counted.begin(), counted.end(), r) != counted.end()) {
            continue;
        }
        for (int j = i + 1; j < hand.cards.size(); j++) {
            if (hand.cards[j].rank == r) {
                pairsFound++;
                counted.push_back(r);
                break;
            }
        }
    }
    return pairsFound >= 2;
}

HandRank TwoPairChecker::check(const Hand& hand) {
    if (isTwoPair(hand)) {
        std::cout << "Detected Two Pair\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker) {
        return nextChecker->check(hand);
    }
    return HandRank::HIGH_CARD;
}
