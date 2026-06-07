#include "JokerManager.h"

void JokerManager::addJoker(std::unique_ptr<JokerCard> joker) {
    jokers.push_back(std::move(joker));
}

void JokerManager::notifyAll(ScoreEvent& event) {
    for (auto& joker : jokers) {
        joker->onScoreCalculated(event);
    }
}
