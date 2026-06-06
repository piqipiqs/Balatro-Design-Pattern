#ifndef HANDPLAYER_H
#define HANDPLAYER_H

#include "Hand.h"
#include "ScoringRule.h"
#include "joker/JokerManager.h"

class HandPlayer {
public:
    HandPlayer(ScoringRule& scoringRule, JokerManager& jokerManager);

    int play(const Hand& hand);

private:
    ScoringRule& scoringRule;
    JokerManager& jokerManager;
};

#endif
