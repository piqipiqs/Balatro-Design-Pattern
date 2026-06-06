#ifndef FLUSHJOKER_H
#define FLUSHJOKER_H

#include "JokerCard.h"

class FlushJoker : public JokerCard {
public:
    FlushJoker() : JokerCard("Flush Joker", "If hand is a Flush, gain x1.5 Mult") {}

    void onScoreCalculated(ScoreEvent& event) override;
};

#endif
