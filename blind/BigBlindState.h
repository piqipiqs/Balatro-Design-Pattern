#ifndef BIGBLINDSTATE_H
#define BIGBLINDSTATE_H

#include "BlindState.h"

// Big Blind — second blind in the progression
// Transitions to: BossBlindState
class BigBlindState : public BlindState {
public:
    explicit BigBlindState(int ante);

    std::string getName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;
    void nextState(RunSessionState& session) const override;
    std::unique_ptr<RewardCommand> createSkipReward() const override;

private:
    int ante;
};

#endif