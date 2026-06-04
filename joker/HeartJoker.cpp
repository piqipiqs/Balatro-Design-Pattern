#include <iostream>
#include "HeartJoker.h"

void HeartJoker::onScoreCalculated(ScoreEvent& event) {
    int count = 0;
    for (const Card& card : event.hand.cards) {
        if (card.suit == Suit::HEARTS) {
            count++;
        }
    }
    if (count > 0) {
        std::cout << "[HeartJoker] " << count << " Heart(s) found! +" << (count * 30) << " Chips\n";
        event.chips += count * 30;
    }
}
