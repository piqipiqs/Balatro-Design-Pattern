#include "BonusHandCommand.h"
#include "../RunSessionState.h"
#include <iostream>

void BonusHandCommand::execute(RunSessionState& session) {
    session.runtime.remainingHands += 1;
    std::cout << "[Reward] Bonus hand applied! +1 hand this blind.\n";
}

RewardTiming BonusHandCommand::getTiming() const {
    return RewardTiming::NextBlind;
}

std::string BonusHandCommand::getDescription() const {
    return "Gain +1 hand next blind";
}
