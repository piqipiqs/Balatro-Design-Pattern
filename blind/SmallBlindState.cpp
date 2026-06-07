#include "SmallBlindState.h"
#include "BigBlindState.h"
#include "../RunSessionState.h"
#include "../command/BonusHandCommand.h"

SmallBlindState::SmallBlindState(int ante)
    : ante(ante) {}

std::string SmallBlindState::getName() const {
    return "Small Blind";
}

int SmallBlindState::getTargetScore() const {
    return (BASE_BLIND_TARGETS[std::min(ante - 1, MAX_ANTE - 1)] * 1);
}

int SmallBlindState::getRewardMoney() const {
    return 3;
}

void SmallBlindState::nextState(RunSessionState& session) const {
    session.persistent.currentBlind = std::make_unique<BigBlindState>(ante);
}

std::unique_ptr<RewardCommand> SmallBlindState::createSkipReward() const {
    return std::make_unique<BonusHandCommand>();
}

bool SmallBlindState::canSkip() const { return true; }
