#ifndef THREEOFAKINDCHECKER_H
#define THREEOFAKINDCHECKER_H
#include "PokerHandChecker.h"

class ThreeOfAKindChecker : public PokerHandChecker {
public:
    ScoreResult check(const Hand& hand) override;
};
#endif
