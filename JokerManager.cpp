#include "JokerManager.h"
#include <iostream>

void JokerManager::addJoker(std::unique_ptr<IJokerCard> joker) {
    jokers.push_back(std::move(joker));
}

void JokerManager::notifyAll(ScoreEvent& event) {
    for (auto& joker : jokers) {
        joker->update(event);
    }
}

void JokerManager::applyAll() {
    // Stub for applying all joker effects
    std::cout << "Applying all joker effects..." << std::endl;
}