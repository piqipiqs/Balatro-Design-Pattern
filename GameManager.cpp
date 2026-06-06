#include <iostream>
#include "GameManager.h"

void GameManager::addJoker(std::unique_ptr<JokerCard> joker) {
    jokerManager.addJoker(std::move(joker));
}

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    // 1. Generate and choose hand
    Hand generatedHand = handGenerator.generateHand();

    choosenHand.chooseHand(generatedHand);

    Hand hand = choosenHand.getHand();

    handPlayer.playHand(hand);

    // 2. Get base chips and mult from scoring rule
    ScoreResult result = scoringRule.scoreHand(hand);

    // 3. Build score event for jokers
    ScoreEvent event;
    event.hand = hand;
    event.handRank = result.handRank;
    event.chips = result.chips;
    event.mult = result.mult;

    // 4. Notify all jokers to observe and apply their effects
    jokerManager.notifyAll(event);

    // 5. Compute final score after joker effects
    int finalScore = static_cast<int>(event.chips * event.mult);

    std::cout << "Chips: " << event.chips << "\n";
    std::cout << "Mult:  " << event.mult  << "\n";
    std::cout << "Final score: " << finalScore << "\n";

    // 6. Check win and reward
    bool win = blindRule.checkBlind(finalScore);

    int reward = rewardRule.earnMoney(win, finalScore);

    std::cout << "Money gained: " << reward << "\n";
    std::cout << "=== Run Ended ===\n";
}
