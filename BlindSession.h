#ifndef BLINDSESSION_H
#define BLINDSESSION_H

#include "Deck.h"
#include "HandState.h"
#include "HandPlayer.h"
#include "BlindRule.h"
#include "RunSessionState.h"

class BlindSession {
public:
    BlindSession(HandPlayer& handPlayer, BlindRule blindRule, RunSessionState& session);

    bool run(); // returns true if blind defeated

private:
    HandPlayer& handPlayer;
    BlindRule blindRule;
    RunSessionState& session;
    Deck deck;
    HandState handState;

    void displayState() const;
    void displayCards() const;
    std::vector<int> promptCardSelection(int maxSelect) const;
    char promptAction() const;
};

#endif
