#ifndef SCORERESULT_H
#define SCORERESULT_H

#include "HandRank.h"

struct ScoreResult {
    HandRank handRank;
    int chips;
    float mult;
};

#endif // SCORERESULT_H
