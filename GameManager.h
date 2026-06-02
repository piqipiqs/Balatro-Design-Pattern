#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"
#include "ChoosenHand.h"
#include "JokerManager.h"

class GameManager {
public:
    void runSession();

private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;
    ChoosenHand choosenHand;
    JokerManager jokerManager;
};

#endif