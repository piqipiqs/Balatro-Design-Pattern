#ifndef ROYALFLUSHCHECKER_H
#define ROYALFLUSHCHECKER_H
#include "PokerHandChecker.h"
class RoyalFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
#endif