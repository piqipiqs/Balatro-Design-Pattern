#ifndef FACECARDJOKER_H
#define FACECARDJOKER_H

#include "JokerCard.h"

class FaceCardJoker : public JokerCard {
public:
    FaceCardJoker() : JokerCard("Face Card Joker", "Gain +2 Mult for each face card (J/Q/K) in hand") {}

    void onScoreCalculated(ScoreEvent& event) override;
};

#endif
