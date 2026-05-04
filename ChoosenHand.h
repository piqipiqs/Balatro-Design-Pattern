#ifndef CHOOSENHAND_H
#define CHOOSENHAND_H

#include "Hand.h"

class ChoosenHand {
public:
    ChoosenHand();

    void chooseHand(const Hand& hand);
    Hand getHand() const;
    bool hasChoosenHand() const;
    void resetChoosenHand();

private:
    Hand selectedHand;
    bool isChoosen;
};

#endif