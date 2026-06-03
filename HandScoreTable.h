#ifndef HANDSCORETABLE_H
#define HANDSCORETABLE_H

#include <map>
#include "HandRank.h"

class HandScoreTable
{
public:
    HandScoreTable();
    ~HandScoreTable();

    void initialize();

    int getChips(HandRank hand) const;
    int getMultiplier(HandRank hand) const;

    void upgradeChips(HandRank hand, int amount);
    void upgradeMultiplier(HandRank hand, int amount);

private:
    std::map<HandRank, int> chipsTable;
    std::map<HandRank, int> multiplierTable;
};

#endif // HANDSCORETABLE_H
