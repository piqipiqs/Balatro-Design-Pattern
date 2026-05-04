#include <iostream>
#include "GameManager.h"

void GameManager::runSession() {
    std::cout << "=== RUN START ===\n";

    // 1. Generate Hand
    Hand hand = handGenerator.generateHand();

    // 2. Play Hand
    handPlayer.playHand();

    // 3. Score Hand
    int score = scoringRule.scoreHand(hand);

    // 4. Check Win Condition
    bool win = blindRule.checkBlind(score);

    // 5. Earn Reward
    int reward = rewardRule.earnMoney(win, score);

    std::cout << "Final Reward: " << reward << "\n";
    std::cout << "=== RUN END ===\n";
}