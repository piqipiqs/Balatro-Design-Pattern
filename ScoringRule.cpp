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
    ScoreResult result = flushFive.check(hand);

    result.chips = scoreTable.getChips(result.handRank);
    result.mult = static_cast<float>(scoreTable.getMultiplier(result.handRank));

    std::cout << "Base Score: chips = " << result.chips << " x mult = " << result.mult << "\n";

    return result;
}
