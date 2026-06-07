#include "GameManager.h"
#include "BlindSession.h"
#include "blind/SmallBlindState.h"
#include <iostream>
#include <algorithm>

GameManager::GameManager()
    : handPlayer(scoringRule, jokerManager) {
    session.persistent.currentBlind = std::make_unique<SmallBlindState>(1);
}

void GameManager::addJoker(std::unique_ptr<JokerCard> joker) {
    jokerManager.addJoker(std::move(joker));
}

void GameManager::run() {
    std::cout << "=== Run Started ===\n";

    while (true) {
        BlindState* blind = session.persistent.currentBlind.get();

        std::cout << "\n=== " << blind->getName()
                  << " | Ante: " << session.persistent.ante
                  << " | Target: " << blind->getTargetScore()
                  << " | Money: $" << session.persistent.money << " ===\n";

        bool play = true;
        if (blind->canSkip()) {
            // Show what reward the player would get for skipping
            auto previewReward = blind->createSkipReward();
            std::cout << "Skip reward: " << previewReward->getDescription() << "\n";

            play = promptPlayOrSkip();
        } else {
            std::cout << "Boss Blind cannot be skipped! You must play.\n";
        }

        if (!play) {
            // Skip flow — create reward, resolve choice, then execute or store
            auto reward = blind->createSkipReward();
            reward->resolveChoice(session);

            if (reward->getTiming() == RewardTiming::Start) {
                reward->execute(session);
            } else {
                session.persistent.pendingCommands.push_back(std::move(reward));
            }

            blind->nextState(session);
            continue;
        }

        // Reset runtime state for this blind
        session.runtime.blindScore = 0;
        session.runtime.remainingHands = 4;
        session.runtime.remainingDiscards = 3;

        // Execute pending NextBlind commands AFTER reset so bonus hands stack correctly
        executePendingCommands(RewardTiming::NextBlind);

        // Run the blind session — returns true if player won
        bool won = runBlindSession();

        if (won) {
            int reward = blind->getRewardMoney();
            awardMoney(reward);

            // Check if ante increases (Boss Blind cleared)
            int anteBefore = session.persistent.ante;
            blind->nextState(session);
            int anteAfter = session.persistent.ante;

            if (anteAfter > anteBefore) {
                std::cout << "=== Ante " << anteBefore << " cleared! Moving to Ante "
                          << anteAfter << " ===\n";
                executePendingCommands(RewardTiming::NextAnte);
            }
        } else {
            std::cout << "=== Run Over! ===\n";
            break;
        }
    }
}

bool GameManager::promptPlayOrSkip() const {
    char input = 0;
    while (input != 'p' && input != 's') {
        std::cout << "[P]lay or [S]kip this blind? ";
        std::string line;
        std::getline(std::cin, line);
        if (!line.empty()) {
            input = static_cast<char>(std::tolower(line[0]));
        }
        if (input != 'p' && input != 's') {
            std::cout << "Invalid input. Enter P or S.\n";
        }
    }
    return input == 'p';
}

void GameManager::executePendingCommands(RewardTiming timing) {
    auto& commands = session.persistent.pendingCommands;

    for (auto& cmd : commands) {
        if (cmd->getTiming() == timing) {
            std::cout << "[Executing reward] " << cmd->getDescription() << "\n";
            cmd->execute(session);
        }
    }

    commands.erase(
        std::remove_if(commands.begin(), commands.end(),
            [timing](const std::unique_ptr<RewardCommand>& cmd) {
                return cmd->getTiming() == timing;
            }),
        commands.end()
    );
}

bool GameManager::runBlindSession() {
    BlindRule blindRule(session.persistent.currentBlind->getTargetScore());
    BlindSession blindSession(handPlayer, blindRule, session);
    return blindSession.run();
}

void GameManager::awardMoney(int amount) {
    int earned = rewardRule.earnMoney(amount, session.runtime.remainingHands);
    session.persistent.money += earned;
    std::cout << "Total money: $" << session.persistent.money << "\n";
}
