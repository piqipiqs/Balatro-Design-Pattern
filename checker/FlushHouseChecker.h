#ifndef FLUSHHOUSECHECKER_H
#define FLUSHHOUSECHECKER_H
#include "PokerHandChecker.h"
class FlushHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
#endif