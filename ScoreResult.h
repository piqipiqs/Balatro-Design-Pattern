#ifndef SCORERESULT_H
#define SCORERESULT_H

#include <vector>
#include "HandRank.h"
#include "Card.h"

struct ScoreResult {
    HandRank handRank;
    int chips;
    float mult;
    std::vector<Card> scoringCards;
};

#endif // SCORERESULT_H
