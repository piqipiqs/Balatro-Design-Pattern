#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include "ScoringRule.h"
#include "HandPlayer.h"
#include "RewardRule.h"
#include "RunSessionState.h"
#include "joker/JokerManager.h"

class GameManager {
public:
    GameManager();

    void addJoker(std::unique_ptr<JokerCard> joker);
    void run();

private:
    ScoringRule scoringRule;
    JokerManager jokerManager;
    HandPlayer handPlayer;
    RunSessionState session;
    RewardRule rewardRule;

    bool promptPlayOrSkip() const;
    void executePendingCommands(RewardTiming timing);
    bool runBlindSession(); // returns true if blind defeated
    void awardMoney(int amount);
};

#endif
