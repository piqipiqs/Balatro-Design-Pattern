#include "HandPlayer.h"
#include "ScoreEvent.h"
#include "CardUtils.h"
#include <iostream>

HandPlayer::HandPlayer(ScoringRule& scoringRule, JokerManager& jokerManager)
    : scoringRule(scoringRule), jokerManager(jokerManager) {}

static int cardChipValue(Rank rank) {
    int r = static_cast<int>(rank);
    if (r >= 2 && r <= 9) return r;
    if (r == 10) return 10;
    if (r == static_cast<int>(Rank::JACK))  return 10;
    if (r == static_cast<int>(Rank::QUEEN)) return 10;
    if (r == static_cast<int>(Rank::KING))  return 10;
    if (r == static_cast<int>(Rank::ACE))   return 11;
    return 0;
}

int HandPlayer::play(const Hand& hand) {
    // 1. Score the hand
    ScoreResult result = scoringRule.scoreHand(hand);

    // 2. Print scoring cards
    std::cout << "Scoring cards: ";
    for (int i = 0; i < static_cast<int>(result.scoringCards.size()); i++) {
        std::cout << rankToString(result.scoringCards[i].rank)
                  << " of " << suitToString(result.scoringCards[i].suit);
        if (i < static_cast<int>(result.scoringCards.size()) - 1) std::cout << ", ";
    }
    std::cout << "\n";

    // 3. Add each scoring card's chip value
    for (const Card& c : result.scoringCards) {
        result.chips += cardChipValue(c.rank);
    }

    // 4. Build score event with only scoring cards
    ScoreEvent event;
    event.hand.cards = result.scoringCards;
    event.handRank = result.handRank;
    event.chips = result.chips;
    event.mult = result.mult;

    // 5. Apply joker effects
    jokerManager.notifyAll(event);

    // 6. Compute final score
    int finalScore = static_cast<int>(event.chips * event.mult);

    std::cout << "Chips: " << event.chips << " | Mult: " << event.mult
              << " | Score: " << finalScore << "\n";

    return finalScore;
}
