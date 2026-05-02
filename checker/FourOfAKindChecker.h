#ifndef FOUROFAKINDCHECKER_H
#define FOUROFAKINDCHECKER_H
#include "PokerHandChecker.h"
class FourOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
#endif