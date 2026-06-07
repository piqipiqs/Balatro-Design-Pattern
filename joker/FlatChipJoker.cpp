#include <iostream>
#include "FlatChipJoker.h"

void FlatChipJoker::onScoreCalculated(ScoreEvent& event) {
    std::cout << "[FlatChipJoker] Always triggers! +50 Chips\n";
    event.chips += 50;
}
