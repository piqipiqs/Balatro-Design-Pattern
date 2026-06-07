#ifndef REWARDCOMMAND_H
#define REWARDCOMMAND_H

#include <string>

class RunSessionState;

// When the reward command should be executed
enum class RewardTiming {
    Start,      // At the start of the run
    NextBlind,  // At the start of the next blind
    NextAnte    // At the start of the next ante
};

// Abstract interface for all reward commands (Command Pattern)
class RewardCommand {
public:
    virtual ~RewardCommand() = default;

    // Executes the reward effect on the session state
    virtual void execute(RunSessionState& session) = 0;

    // Returns when this command should trigger
    virtual RewardTiming getTiming() const = 0;

    // Returns a human-readable description of the reward
    virtual std::string getDescription() const = 0;
};

#endif