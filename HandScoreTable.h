#pragma once

#include <map>
#include "PokerHand.h"

class HandScoreTable
{
public:
    HandScoreTable();
    ~HandScoreTable();

    void Initialize();

    int getChips(PokerHand hand) const;
    int getMultiplier(PokerHand hand) const;

    void upgradeChips(PokerHand hand, int amount);
    void upgradeMultiplier(PokerHand hand, int amount);

private:
    std::map<PokerHand, int> chipsTable;
    std::map<PokerHand, int> multiplierTable;
};
