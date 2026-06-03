#include "HandScoreTable.h"

HandScoreTable::HandScoreTable() {
    initialize();
}

HandScoreTable::~HandScoreTable() {}

void HandScoreTable::initialize() {
    chipsTable[HandRank::HIGH_CARD] = 5;
    chipsTable[HandRank::PAIR] = 10;
    chipsTable[HandRank::TWO_PAIR] = 20;
    chipsTable[HandRank::THREE_OF_A_KIND] = 30;
    chipsTable[HandRank::STRAIGHT] = 30;
    chipsTable[HandRank::FLUSH] = 35;
    chipsTable[HandRank::FULL_HOUSE] = 40;
    chipsTable[HandRank::FOUR_OF_A_KIND] = 60;
    chipsTable[HandRank::STRAIGHT_FLUSH] = 100;
    chipsTable[HandRank::ROYAL_FLUSH] = 100;
    chipsTable[HandRank::FIVE_OF_A_KIND] = 120;
    chipsTable[HandRank::FLUSH_HOUSE] = 140;
    chipsTable[HandRank::FLUSH_FIVE] = 160;

    multiplierTable[HandRank::HIGH_CARD] = 1;
    multiplierTable[HandRank::PAIR] = 2;
    multiplierTable[HandRank::TWO_PAIR] = 2;
    multiplierTable[HandRank::THREE_OF_A_KIND] = 3;
    multiplierTable[HandRank::STRAIGHT] = 4;
    multiplierTable[HandRank::FLUSH] = 4;
    multiplierTable[HandRank::FULL_HOUSE] = 4;
    multiplierTable[HandRank::FOUR_OF_A_KIND] = 7;
    multiplierTable[HandRank::STRAIGHT_FLUSH] = 8;
    multiplierTable[HandRank::ROYAL_FLUSH] = 8;
    multiplierTable[HandRank::FIVE_OF_A_KIND] = 12;
    multiplierTable[HandRank::FLUSH_HOUSE] = 14;
    multiplierTable[HandRank::FLUSH_FIVE] = 16;
}

int HandScoreTable::getChips(HandRank hand) const {
    auto it = chipsTable.find(hand);
    if (it != chipsTable.end())
        return it->second;
    return 0;
}

int HandScoreTable::getMultiplier(HandRank hand) const {
    auto it = multiplierTable.find(hand);
    if (it != multiplierTable.end())
        return it->second;
    return 0;
}

void HandScoreTable::upgradeChips(HandRank hand, int amount) {
    chipsTable[hand] += amount;
}

void HandScoreTable::upgradeMultiplier(HandRank hand, int amount) {
    multiplierTable[hand] += amount;
}
