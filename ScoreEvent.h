#ifndef SCOREEVENT_H
#define SCOREEVENT_H

#include "Hand.h"
#include "HandRank.h"

struct ScoreEvent {
    Hand hand;
    HandRank handRank;
    int chips;
    float mult;
};

#endif // SCOREEVENT_H
