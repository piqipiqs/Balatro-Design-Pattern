#ifndef HIGHCARDCHECKER_H
#define HIGHCARDCHECKER_H
#include "PokerHandChecker.h"
class HighCardChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override;
};
#endif