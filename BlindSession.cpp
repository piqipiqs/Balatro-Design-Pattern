#include "BlindSession.h"
#include "CardUtils.h"
#include <iostream>
#include <sstream>
#include <set>

BlindSession::BlindSession(HandPlayer& handPlayer, BlindRule blindRule, RunSessionState& session)
    : handPlayer(handPlayer),
      blindRule(blindRule),
      session(session) {}

bool BlindSession::run() {
    std::cout << "\n=== Blind Started | Target: " << blindRule.getTarget() << " ===\n";

    // Inject any bonus cards from pending rewards into the deck
    for (const Card& c : session.persistent.bonusCards) {
        deck.injectCard(c);
    }

    handState.refill(deck);

    while (session.runtime.remainingHands > 0) {
        displayState();
        displayCards();

        char action = promptAction();

        if (action == 'p') {
            std::cout << "Select up to 5 cards to play (e.g. 1 3 5): ";
            std::vector<int> indices = promptCardSelection(HandState::MAX_SELECT);
            if (indices.empty()) {
                std::cout << "No cards selected. Try again.\n";
                continue;
            }

            Hand hand = handState.getSelectedHand(indices);
            int score = handPlayer.play(hand);
            session.runtime.blindScore += score;

            handState.removeCards(indices);
            handState.refill(deck);
            session.runtime.remainingHands--;

            std::cout << "Total score: " << session.runtime.blindScore
                      << " / " << blindRule.getTarget() << "\n";

            if (blindRule.isDefeated(session.runtime.blindScore)) {
                std::cout << "=== Blind Defeated! ===\n";
                return true;
            }

        } else if (action == 'd') {
            if (session.runtime.remainingDiscards <= 0) {
                std::cout << "No discards remaining!\n";
                continue;
            }
            std::cout << "Select up to 5 cards to discard (e.g. 1 3 5): ";
            std::vector<int> indices = promptCardSelection(HandState::MAX_SELECT);
            if (indices.empty()) {
                std::cout << "No cards selected. Try again.\n";
                continue;
            }

            handState.removeCards(indices);
            handState.refill(deck);
            session.runtime.remainingDiscards--;
        }
    }

    std::cout << "=== Out of hands! Blind failed. Final score: "
              << session.runtime.blindScore
              << " / " << blindRule.getTarget() << " ===\n";
    return false;
}

void BlindSession::displayState() const {
    std::cout << "\n--- Hands left: " << session.runtime.remainingHands
              << " | Discards left: " << session.runtime.remainingDiscards
              << " | Score: " << session.runtime.blindScore
              << " / " << blindRule.getTarget()
              << " | Deck: " << deck.remaining() << " ---\n";
}

void BlindSession::displayCards() const {
    const auto& cards = handState.getCards();
    std::cout << "Your hand:\n";
    for (int i = 0; i < static_cast<int>(cards.size()); i++) {
        std::cout << "  [" << (i + 1) << "] "
                  << rankToString(cards[i].rank)
                  << " of "
                  << suitToString(cards[i].suit) << "\n";
    }
}

char BlindSession::promptAction() const {
    char action = 0;
    while (action != 'p' && action != 'd') {
        std::cout << "[P]lay or [D]iscard? ";
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty()) {
            action = static_cast<char>(std::tolower(input[0]));
        }
        if (action != 'p' && action != 'd') {
            std::cout << "Invalid input. Enter P or D.\n";
        }
    }
    return action;
}

std::vector<int> BlindSession::promptCardSelection(int maxSelect) const {
    std::vector<int> indices;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss(line);

    std::set<int> seen;
    int val;
    while (ss >> val) {
        int idx = val - 1;
        if (idx < 0 || idx >= handState.size()) {
            std::cout << "Invalid index " << val << " ignored.\n";
            continue;
        }
        if (seen.count(idx)) {
            std::cout << "Duplicate index " << val << " ignored.\n";
            continue;
        }
        seen.insert(idx);
        indices.push_back(idx);
        if (static_cast<int>(indices.size()) >= maxSelect) break;
    }
    return indices;
}
