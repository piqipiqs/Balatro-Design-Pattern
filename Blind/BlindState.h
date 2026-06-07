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

    // Returns the name of this blind (e.g. "Small Blind")
    virtual std::string getName() const = 0;

    // Returns the target score required to clear this blind
    virtual int getTargetScore() const = 0;

    // Returns the money reward for clearing this blind
    virtual int getRewardMoney() const = 0;

    // Transitions to the next blind state
    virtual void nextState(RunSessionState& session) const = 0;

    // Creates and returns the skip reward command for this blind
    virtual std::unique_ptr<RewardCommand> createSkipReward() const = 0;
};

#endif 