#ifndef BLINDSTATE_H
#define BLINDSTATE_H

#include <string>
#include <memory>
#include <algorithm>

class RunSessionState;
class RewardCommand;

// Max ante — game ends after clearing Ante 8 Boss Blind
constexpr int MAX_ANTE = 8;

// Hardcoded base target scores
constexpr int BASE_BLIND_TARGETS[] = { 300, 1000, 2500,  6000,  15000,  40000, 100000, 300000 };\

// Abstract interface for all blind states (State Pattern)
class BlindState {
public:
    virtual ~BlindState() = default;

    virtual std::string getName() const = 0;
    virtual int getTargetScore() const = 0;
    virtual int getRewardMoney() const = 0;
    virtual void nextState(RunSessionState& session) const = 0;
    virtual std::unique_ptr<RewardCommand> createSkipReward() const = 0;

    // Returns whether this blind can be skipped (Boss Blind cannot)
    virtual bool canSkip() const = 0;
};

#endif
