#include <iostream>
#include "ChoosenHand.h"

ChoosenHand::ChoosenHand()
    : isChoosen(false) {}

void ChoosenHand::chooseHand(const Hand& hand) {
    selectedHand = hand;
    isChoosen = true;

    std::cout << "Hand choosen with: " << selectedHand.cards.size() << " cards\n";
}

Hand ChoosenHand::getHand() const {
    return selectedHand;
}

bool ChoosenHand::hasChoosenHand() const {
    return isChoosen;
}

void ChoosenHand::resetChoosenHand() {
    selectedHand = Hand();
    isChoosen = false;

    std::cout << "Choosen hand reset.\n";
}
