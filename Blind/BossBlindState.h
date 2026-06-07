#ifndef BOSSBLINDSTATE_H
#define BOSSBLINDSTATE_H

#include "BlindState.h"

// Boss Blind — final blind in the progression
// Increments ante and transitions back to: SmallBlindState
class BossBlindState : public BlindState {
public:
    explicit BossBlindState(int ante);

    std::string getName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;
    void nextState(RunSessionState& session) const override;
    std::unique_ptr<RewardCommand> createSkipReward() const override;

private:
    int ante;
};

#endif