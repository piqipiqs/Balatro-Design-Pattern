#ifndef PAIRCHECKER_H
#define PAIRCHECKER_H
#include "PokerHandChecker.h"

class PairChecker : public PokerHandChecker {
public:
    ScoreResult check(const Hand& hand) override;
};
#endif
