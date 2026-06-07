#ifndef BLINDSTATE_H
#define BLINDSTATE_H

#include <string>
#include <memory>

class RunSessionState;
class RewardCommand;

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