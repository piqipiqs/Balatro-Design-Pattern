#ifndef POKERHANDCHECKER_H
#define POKERHANDCHECKER_H

#include "../Hand.h"
#include "../HandRank.h"
#include "../ScoreResult.h"

class PokerHandChecker {
public:
    virtual ScoreResult check(const Hand& hand) = 0;
    void setNext(PokerHandChecker* next);

protected:
    PokerHandChecker* nextChecker = nullptr;
};

#endif
