#ifndef FLUSHCHECKER_H
#define FLUSHCHECKER_H
#include "PokerHandChecker.h"

class FlushChecker : public PokerHandChecker {
public:
    ScoreResult check(const Hand& hand) override;
};
#endif
