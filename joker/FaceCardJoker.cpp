#include <iostream>
#include "FaceCardJoker.h"

void FaceCardJoker::onScoreCalculated(ScoreEvent& event) {
    int count = 0;
    for (const Card& card : event.hand.cards) {
        if (card.rank == Rank::JACK  ||
            card.rank == Rank::QUEEN ||
            card.rank == Rank::KING) {
            count++;
        }
    }
    if (count > 0) {
        std::cout << "[FaceCardJoker] " << count << " face card(s) found! +" << (count * 2) << " Mult\n";
        event.mult += count * 2;
    }
}
