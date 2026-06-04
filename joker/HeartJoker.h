#ifndef HEARTJOKER_H
#define HEARTJOKER_H

#include "JokerCard.h"

class HeartJoker : public JokerCard {
public:
    HeartJoker() : JokerCard("Heart Joker", "Gain +30 Chips for each Heart card in hand") {}

    void onScoreCalculated(ScoreEvent& event) override;
};

#endif
