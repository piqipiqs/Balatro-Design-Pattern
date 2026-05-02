#ifndef TWOPAIRCHECKER_H
#define TWOPAIRCHECKER_H
#include "PokerHandChecker.h"
class TwoPairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
#endif