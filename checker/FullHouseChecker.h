#ifndef FULLHOUSECHECKER_H
#define FULLHOUSECHECKER_H
#include "PokerHandChecker.h"

class FullHouseChecker : public PokerHandChecker {
public:
    ScoreResult check(const Hand& hand) override;
};
#endif
