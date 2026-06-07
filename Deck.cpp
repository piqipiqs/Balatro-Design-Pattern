#include "Deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck() {
    initialize();
    shuffle();
}

void Deck::initialize() {
    cards.clear();
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r <= 14; r++) {
            cards.push_back({static_cast<Rank>(r), static_cast<Suit>(s)});
        }
    }
}

void Deck::shuffle() {
    std::mt19937 rng(std::random_device{}());
    std::shuffle(cards.begin(), cards.end(), rng);
}

std::vector<Card> Deck::draw(int n) {
    if (n > static_cast<int>(cards.size())) {
        throw std::runtime_error("Not enough cards in deck");
    }
    std::vector<Card> drawn(cards.end() - n, cards.end());
    cards.erase(cards.end() - n, cards.end());
    return drawn;
}

void Deck::injectCard(const Card& card) {
    // Insert at a random position so it shuffles naturally
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(cards.size()));
    cards.insert(cards.begin() + dist(rng), card);
}

int Deck::remaining() const {
    return static_cast<int>(cards.size());
}
