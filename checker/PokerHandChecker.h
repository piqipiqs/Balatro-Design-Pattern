#ifndef POKERHANDCHECKER_H
#define POKERHANDCHECKER_H

#include "../Hand.h"
#include "../HandRank.h"

class PokerHandChecker {
public:
    virtual HandRank check(const Hand& hand) = 0;
    void setNext(PokerHandChecker* next);

protected:
    PokerHandChecker* nextChecker = nullptr;
};

#endif
