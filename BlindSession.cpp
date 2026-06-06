#include "BlindSession.h"
#include <iostream>
#include <sstream>
#include <set>

BlindSession::BlindSession(HandPlayer& handPlayer, BlindRule blindRule)
    : handPlayer(handPlayer),
      blindRule(blindRule),
      handsLeft(MAX_HANDS),
      discardsLeft(MAX_DISCARDS),
      currentScore(0) {}

bool BlindSession::run() {
    std::cout << "\n=== Blind Started | Target: " << blindRule.getTarget() << " ===\n";

    handState.refill(deck);

    while (handsLeft > 0) {
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
            currentScore += score;

            handState.removeCards(indices);
            handState.refill(deck);
            handsLeft--;

            std::cout << "Total score: " << currentScore << " / " << blindRule.getTarget() << "\n";

            if (blindRule.isDefeated(currentScore)) {
                std::cout << "=== Blind Defeated! ===\n";
                return true;
            }

        } else if (action == 'd') {
            if (discardsLeft <= 0) {
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
            discardsLeft--;
        }
    }

    std::cout << "=== Out of hands! Blind failed. Final score: "
              << currentScore << " / " << blindRule.getTarget() << " ===\n";
    return false;
}

void BlindSession::displayState() const {
    std::cout << "\n--- Hands left: " << handsLeft
              << " | Discards left: " << discardsLeft
              << " | Score: " << currentScore
              << " / " << blindRule.getTarget() << " ---\n";
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
        int idx = val - 1; // convert 1-based to 0-based
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

const char* BlindSession::rankToString(Rank rank) {
    switch (rank) {
        case Rank::TWO:   return "2";
        case Rank::THREE: return "3";
        case Rank::FOUR:  return "4";
        case Rank::FIVE:  return "5";
        case Rank::SIX:   return "6";
        case Rank::SEVEN: return "7";
        case Rank::EIGHT: return "8";
        case Rank::NINE:  return "9";
        case Rank::TEN:   return "10";
        case Rank::JACK:  return "Jack";
        case Rank::QUEEN: return "Queen";
        case Rank::KING:  return "King";
        case Rank::ACE:   return "Ace";
        default:          return "?";
    }
}

const char* BlindSession::suitToString(Suit suit) {
    switch (suit) {
        case Suit::SPADES:   return "Spades";
        case Suit::HEARTS:   return "Hearts";
        case Suit::CLUBS:    return "Clubs";
        case Suit::DIAMONDS: return "Diamonds";
        default:             return "?";
    }
}
