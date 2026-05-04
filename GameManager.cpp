#include <iostream>
#include "GameManager.h"

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    Hand generatedHand = handGenerator.generateHand();

    choosenHand.chooseHand(generatedHand);

    Hand hand = choosenHand.getHand();

    handPlayer.playHand(hand);

    int score = scoringRule.scoreHand(hand);

    bool win = blindRule.checkBlind(score);

    int reward = rewardRule.earnMoney(win, score);

    std::cout << "Money gained: " << reward << "\n";
    std::cout << "=== Run Ended ===\n";
}