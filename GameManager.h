#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "joker/JokerManager.h"

class GameManager {
public:
    GameManager();

    void addJoker(std::unique_ptr<JokerCard> joker);
    void run(int blindTarget);

private:
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    JokerManager jokerManager;
};

#endif
