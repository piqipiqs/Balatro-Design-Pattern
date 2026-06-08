#ifndef REWARDCOMMAND_H
#define REWARDCOMMAND_H

#include <string>

class RunSessionState;

// When the reward command should be executed
enum class RewardTiming {
    Start,      // Executes immediately when the blind is skipped
    NextBlind,  // Executes at the start of the next blind
    NextAnte    // Executes at the start of the next ante
};

// Abstract interface for all reward commands (Command Pattern)
class RewardCommand {
public:
    virtual ~RewardCommand() = default;

    // Executes the reward effect on the session state
    virtual void execute(RunSessionState& session) = 0;

    // Called before execute() if the command needs player input
    // Override this to prompt the player for a choice (e.g. pick a card)
    // Default does nothing — only override when needed
    virtual void resolveChoice(RunSessionState& session) {}

    // Returns when this command should trigger
    virtual RewardTiming getTiming() const = 0;

    // Returns a human-readable description of the reward
    virtual std::string getDescription() const = 0;
};

#endif
