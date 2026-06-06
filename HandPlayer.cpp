#include "HandPlayer.h"
#include "ScoreEvent.h"
#include <iostream>

HandPlayer::HandPlayer(ScoringRule& scoringRule, JokerManager& jokerManager)
    : scoringRule(scoringRule), jokerManager(jokerManager) {}

int HandPlayer::play(const Hand& hand) {
    // 1. Score the hand
    ScoreResult result = scoringRule.scoreHand(hand);

    // 2. Build score event for jokers
    ScoreEvent event;
    event.hand = hand;
    event.handRank = result.handRank;
    event.chips = result.chips;
    event.mult = result.mult;

    // 3. Apply joker effects
    jokerManager.notifyAll(event);

    // 4. Compute final score
    int finalScore = static_cast<int>(event.chips * event.mult);

    std::cout << "Chips: " << event.chips << " | Mult: " << event.mult
              << " | Score: " << finalScore << "\n";

    return finalScore;
}
