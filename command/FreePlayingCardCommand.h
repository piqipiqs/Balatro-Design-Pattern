#ifndef FREEPLAYINGCARDCOMMAND_H
#define FREEPLAYINGCARDCOMMAND_H

#include "RewardCommand.h"
#include "../Card.h"

// Adds a free playing card (player's choice) to the deck
class FreePlayingCardCommand : public RewardCommand {
public:
    // Prompts the player to pick one of 3 random cards
    void resolveChoice(RunSessionState& session) override;

    // Adds the chosen card to persistent.bonusCards
    void execute(RunSessionState& session) override;

    RewardTiming getTiming() const override;
    std::string getDescription() const override;

private:
    Card chosenCard;
    bool hasChosen = false;
};

#endif
