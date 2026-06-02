#include "HandScoreTable.h"

HandScoreTable::HandScoreTable()
{
}

HandScoreTable::~HandScoreTable()
{
}

void HandScoreTable::Initialize()
{
    chipsTable[PokerHand::HighCard] = 5;
    chipsTable[PokerHand::Pair] = 10;
    chipsTable[PokerHand::TwoPair] = 20;
    chipsTable[PokerHand::ThreeOfAKind] = 30;
    chipsTable[PokerHand::Straight] = 30;
    chipsTable[PokerHand::Flush] = 35;
    chipsTable[PokerHand::FullHouse] = 40;
    chipsTable[PokerHand::FourOfAKind] = 60;
    chipsTable[PokerHand::StraightFlush] = 100;
    chipsTable[PokerHand::RoyalFlush] = 100;
    chipsTable[PokerHand::FiveOfAKind] = 120;
    chipsTable[PokerHand::FlushHouse] = 140;
    chipsTable[PokerHand::FlushFive] = 160;

    multiplierTable[PokerHand::HighCard] = 1;
    multiplierTable[PokerHand::Pair] = 2;
    multiplierTable[PokerHand::TwoPair] = 2;
    multiplierTable[PokerHand::ThreeOfAKind] = 3;
    multiplierTable[PokerHand::Straight] = 4;
    multiplierTable[PokerHand::Flush] = 4;
    multiplierTable[PokerHand::FullHouse] = 4;
    multiplierTable[PokerHand::FourOfAKind] = 7;
    multiplierTable[PokerHand::StraightFlush] = 8;
    multiplierTable[PokerHand::RoyalFlush] = 8;
    multiplierTable[PokerHand::FiveOfAKind] = 12;
    multiplierTable[PokerHand::FlushHouse] = 14;
    multiplierTable[PokerHand::FlushFive] = 16;
}

int HandScoreTable::getChips(PokerHand hand) const
{
    auto it = chipsTable.find(hand);
    if (it != chipsTable.end())
        return it->second;
    return 0;
}

int HandScoreTable::getMultiplier(PokerHand hand) const
{
    auto it = multiplierTable.find(hand);
    if (it != multiplierTable.end())
        return it->second;
    return 0;
}

void HandScoreTable::upgradeChips(PokerHand hand, int amount)
{
    chipsTable[hand] += amount;
}

void HandScoreTable::upgradeMultiplier(PokerHand hand, int amount)
{
    multiplierTable[hand] += amount;
}
