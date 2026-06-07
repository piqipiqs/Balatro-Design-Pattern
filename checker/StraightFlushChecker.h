#ifndef STRAIGHTFLUSHCHECKER_H
#define STRAIGHTFLUSHCHECKER_H
#include "PokerHandChecker.h"

class StraightFlushChecker : public PokerHandChecker {
public:
    ScoreResult check(const Hand& hand) override;
};
#endif
