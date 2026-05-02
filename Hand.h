#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

struct Hand {
    std::vector<Card> cards;
    int value;
};

#endif
