#include "HandState.h"
#include <stdexcept>
#include <algorithm>

void HandState::refill(Deck& deck) {
    int needed = MAX_CARDS - static_cast<int>(cards.size());
    if (needed <= 0) return;

    int canDraw = std::min(needed, deck.remaining());
    if (canDraw <= 0) return;

    std::vector<Card> drawn = deck.draw(canDraw);
    cards.insert(cards.end(), drawn.begin(), drawn.end());
}

Hand HandState::getSelectedHand(const std::vector<int>& indices) const {
    if (indices.size() > MAX_SELECT) {
        throw std::runtime_error("Cannot select more than 5 cards");
    }
    Hand hand;
    for (int idx : indices) {
        if (idx < 0 || idx >= static_cast<int>(cards.size())) {
            throw std::runtime_error("Invalid card index");
        }
        hand.cards.push_back(cards[idx]);
    }
    return hand;
}

void HandState::removeCards(const std::vector<int>& indices) {
    // Sort descending so removing by index doesn't shift positions
    std::vector<int> sorted = indices;
    std::sort(sorted.rbegin(), sorted.rend());

    for (int idx : sorted) {
        if (idx < 0 || idx >= static_cast<int>(cards.size())) {
            throw std::runtime_error("Invalid card index");
        }
        cards.erase(cards.begin() + idx);
    }
}

const std::vector<Card>& HandState::getCards() const {
    return cards;
}

int HandState::size() const {
    return static_cast<int>(cards.size());
}
