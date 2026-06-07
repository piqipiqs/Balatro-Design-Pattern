#ifndef FLATCHIPJOKER_H
#define FLATCHIPJOKER_H

#include "JokerCard.h"

class FlatChipJoker : public JokerCard {
public:
    FlatChipJoker() : JokerCard("Flat Chip Joker", "Always gain +50 Chips") {}

    void onScoreCalculated(ScoreEvent& event) override;
};

#endif
