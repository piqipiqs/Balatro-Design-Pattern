#include "FreePlayingCardCommand.h"
#include "../RunSessionState.h"
#include "../CardUtils.h"
#include <iostream>
#include <random>
#include <vector>

static Card generateRandomCard() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> rankDist(2, 14);
    std::uniform_int_distribution<int> suitDist(0, 3);
    return { static_cast<Rank>(rankDist(rng)), static_cast<Suit>(suitDist(rng)) };
}

void FreePlayingCardCommand::resolveChoice(RunSessionState& session) {
    // Generate 3 random cards for the player to choose from
    std::vector<Card> options;
    for (int i = 0; i < 3; i++) {
        options.push_back(generateRandomCard());
    }

    std::cout << "Choose a card to add to your deck:\n";
    for (int i = 0; i < static_cast<int>(options.size()); i++) {
        std::cout << "  [" << (i + 1) << "] "
                  << rankToString(options[i].rank)
                  << " of " << suitToString(options[i].suit) << "\n";
    }

    int choice = 0;
    while (choice < 1 || choice > static_cast<int>(options.size())) {
        std::cout << "Enter choice (1-" << options.size() << "): ";
        std::string line;
        std::getline(std::cin, line);
        try {
            choice = std::stoi(line);
        } catch (...) {
            choice = 0;
        }
        if (choice < 1 || choice > static_cast<int>(options.size())) {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    chosenCard = options[choice - 1];
    hasChosen = true;
    std::cout << "You chose: " << rankToString(chosenCard.rank)
              << " of " << suitToString(chosenCard.suit) << "\n";
}

void FreePlayingCardCommand::execute(RunSessionState& session) {
    if (!hasChosen) {
        // Fallback if resolveChoice wasn't called
        chosenCard = generateRandomCard();
    }
    session.persistent.bonusCards.push_back(chosenCard);
    std::cout << "[Reward] " << rankToString(chosenCard.rank)
              << " of " << suitToString(chosenCard.suit)
              << " added to your deck permanently!\n";
}

RewardTiming FreePlayingCardCommand::getTiming() const {
    return RewardTiming::Start;
}

std::string FreePlayingCardCommand::getDescription() const {
    return "Choose a free playing card to add to your deck";
}
