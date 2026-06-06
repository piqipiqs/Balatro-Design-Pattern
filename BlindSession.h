#ifndef BLINDSESSION_H
#define BLINDSESSION_H

#include "Deck.h"
#include "HandState.h"
#include "HandPlayer.h"
#include "BlindRule.h"

class BlindSession {
public:
    static const int MAX_HANDS = 4;
    static const int MAX_DISCARDS = 3;

    BlindSession(HandPlayer& handPlayer, BlindRule blindRule);

    bool run(); // returns true if blind defeated

private:
    HandPlayer& handPlayer;
    BlindRule blindRule;
    Deck deck;
    HandState handState;

    int handsLeft;
    int discardsLeft;
    int currentScore;

    void displayState() const;
    void displayCards() const;
    std::vector<int> promptCardSelection(int maxSelect) const;
    char promptAction() const;

    static const char* rankToString(Rank rank);
    static const char* suitToString(Suit suit);
};

#endif
