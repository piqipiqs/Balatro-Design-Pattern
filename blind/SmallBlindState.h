#ifndef SMALLBLINDSTATE_H
#define SMALLBLINDSTATE_H

#include "BlindState.h"

// Small Blind — first blind in the progression
// Transitions to: BigBlindState
class SmallBlindState : public BlindState {
public:
    explicit SmallBlindState(int ante);

    std::string getName() const override;
    int getTargetScore() const override;
    int getRewardMoney() const override;
    void nextState(RunSessionState& session) const override;
    std::unique_ptr<RewardCommand> createSkipReward() const override;
    bool canSkip() const override;

private:
    int ante;
};

#endif