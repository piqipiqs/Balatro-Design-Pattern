#include <iostream>
#include "GameManager.h"
#include "BlindSession.h"

GameManager::GameManager()
    : handPlayer(scoringRule, jokerManager) {}

void GameManager::addJoker(std::unique_ptr<JokerCard> joker) {
    jokerManager.addJoker(std::move(joker));
}

void GameManager::run(int blindTarget) {
    BlindRule blindRule(blindTarget);
    BlindSession session(handPlayer, blindRule);

    bool won = session.run();

    if (won) {
        std::cout << "You defeated the blind!\n";
    }
    else {
        std::cout << "You failed the blind.\n";
    }
}

