#include <iostream>
#include "PairJoker.h"

void PairJoker::onScoreCalculated(ScoreEvent& event) {
    if (event.handRank == HandRank::PAIR) {
        std::cout << "[PairJoker] Pair detected! +4 Mult\n";
        event.mult += 4;
    }
}
