#ifndef PAIRJOKER_H
#define PAIRJOKER_H

#include "JokerCard.h"

class PairJoker : public JokerCard {
public:
    PairJoker() : JokerCard("Pair Joker", "If hand contains a Pair, gain +4 Mult") {}

    void onScoreCalculated(ScoreEvent& event) override;
};

#endif
