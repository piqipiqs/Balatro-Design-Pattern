#include <iostream>
#include <algorithm>
#include <random>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::vector<Card> deck;
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r <= 14; r++) {
            deck.push_back({static_cast<Rank>(r), static_cast<Suit>(s)});
        }
    }

    std::mt19937 rng(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), rng);

    Hand hand;
    for (int i = 0; i < 5; i++) {
        hand.cards.push_back(deck[i]);
    }

    std::cout << "Generating hand...\n";
    for (const Card& c : hand.cards) {
        const char* suits[] = {"SPADES", "HEARTS", "CLUBS", "DIAMONDS"};
        const char* ranks[] = {"","","2","3","4","5","6","7","8","9","10","JACK","QUEEN","KING","ACE"};

        std::cout << ranks[static_cast<int>(c.rank)] << " of " << suits[static_cast<int>(c.suit)] << "\n";
    }

    return hand;
}
