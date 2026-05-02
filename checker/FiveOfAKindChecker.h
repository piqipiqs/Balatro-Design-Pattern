#ifndef FIVEOFAKINDCHECKER_H
#define FIVEOFAKINDCHECKER_H
#include "PokerHandChecker.h"
class FiveOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
#endif