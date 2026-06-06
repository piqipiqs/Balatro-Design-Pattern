#include <iostream>
#include "ScoringRule.h"

ScoringRule::ScoringRule() {
    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveKind);
    fiveKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourKind);
    fourKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeKind);
    threeKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);
}

ScoreResult ScoringRule::scoreHand(const Hand& hand) {
    std::cout << "Scoring...\n";

    HandRank rank = flushFive.check(hand);
    int chips = scoreTable.getChips(rank);
    float mult = static_cast<float>(scoreTable.getMultiplier(rank));

    std::cout << "Hand: chips = " << chips << " x mult = " << mult << "\n";

    return ScoreResult{ rank, chips, mult };
}
