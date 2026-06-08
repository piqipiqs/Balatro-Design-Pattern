#include "BigBlindState.h"
#include "BossBlindState.h"
#include "../RunSessionState.h"
#include "../command/FreePlayingCardCommand.h"

BigBlindState::BigBlindState(int ante)
    : ante(ante) {}

std::string BigBlindState::getName() const {
    return "Big Blind";
}

int BigBlindState::getTargetScore() const {
    return (BASE_BLIND_TARGETS[std::min(ante - 1, MAX_ANTE - 1)] * 1.5);
}

int BigBlindState::getRewardMoney() const {
    return 4;
}

void BigBlindState::nextState(RunSessionState& session) const {
    session.persistent.currentBlind = std::make_unique<BossBlindState>(ante);
}

std::unique_ptr<RewardCommand> BigBlindState::createSkipReward() const {
    return std::make_unique<FreePlayingCardCommand>();
}

bool BigBlindState::canSkip() const { return true; }
