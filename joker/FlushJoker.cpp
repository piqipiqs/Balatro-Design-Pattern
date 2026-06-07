#include <iostream>
#include "FlushJoker.h"

void FlushJoker::onScoreCalculated(ScoreEvent& event) {
    if (event.handRank == HandRank::FLUSH) {
        std::cout << "[FlushJoker] Flush detected! x1.5 Mult\n";
        event.mult *= 1.5f;
    }
}
