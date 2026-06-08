#include "BossBlindState.h"
#include "SmallBlindState.h"
#include "../RunSessionState.h"
#include "../command/BonusHandCommand.h"

BossBlindState::BossBlindState(int ante)
    : ante(ante) {}

std::string BossBlindState::getName() const {
    return "Boss Blind";
}

int BossBlindState::getTargetScore() const {
    return (BASE_BLIND_TARGETS[std::min(ante - 1, MAX_ANTE - 1)] * 2);
}

int BossBlindState::getRewardMoney() const {
    return 5;
}

void BossBlindState::nextState(RunSessionState& session) const {
    int nextAnte = ante + 1;
    session.persistent.ante = nextAnte;
    session.persistent.currentBlind = std::make_unique<SmallBlindState>(nextAnte);
}

std::unique_ptr<RewardCommand> BossBlindState::createSkipReward() const {
    return std::make_unique<BonusHandCommand>();
}

bool BossBlindState::canSkip() const { return false; }
