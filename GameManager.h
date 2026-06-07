#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include "ScoringRule.h"
#include "HandPlayer.h"
#include "RunSessionState.h"
#include "joker/JokerManager.h"

class GameManager {
public:
    GameManager();

    // Add a joker to the game
    void addJoker(std::unique_ptr<JokerCard> joker);

    // Start the full run loop
    void run();

private:
    ScoringRule scoringRule;
    JokerManager jokerManager;
    HandPlayer handPlayer;
    RunSessionState session;

    // Prompt player to play or skip the current blind
    // Returns true if play, false if skip
    bool promptPlayOrSkip() const;

    // Execute all pending commands matching the given timing
    void executePendingCommands(RewardTiming timing);

    // Run a single blind session
    void runBlindSession();

    // Award money after clearing a blind
    void awardMoney(int amount);
};

#endif