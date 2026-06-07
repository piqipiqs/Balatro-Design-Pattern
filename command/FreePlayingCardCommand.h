#ifndef FREEPLAYINGCARDCOMMAND_H
#define FREEPLAYINGCARDCOMMAND_H

#include "RewardCommand.h"

// Adds a free random playing card to the deck at the start of the next blind
class FreePlayingCardCommand : public RewardCommand {
public:
    void execute(RunSessionState& session) override;
    RewardTiming getTiming() const override;
    std::string getDescription() const override;
};

#endif