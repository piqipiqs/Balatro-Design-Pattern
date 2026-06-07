#ifndef BONUSHANDCOMMAND_H
#define BONUSHANDCOMMAND_H

#include "RewardCommand.h"

// Gives the player +1 hand at the start of the next blind
class BonusHandCommand : public RewardCommand {
public:
    void execute(RunSessionState& session) override;
    RewardTiming getTiming() const override;
    std::string getDescription() const override;
};

#endif