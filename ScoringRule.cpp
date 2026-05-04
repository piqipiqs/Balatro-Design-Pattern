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

int ScoringRule::scoreHand(const Hand& hand) {
    std::cout << "Scoring...\n";
    flushFive.check(hand);
    return 0;
}