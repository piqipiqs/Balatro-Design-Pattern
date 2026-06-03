#ifndef JOKERCARD_H
#define JOKERCARD_H

#include <string>
#include <utility>
#include "ScoreEvent.h"

class JokerCard {
private:
    std::string name;
    std::string description;

public:
    JokerCard(std::string name, std::string description)
        : name(std::move(name)), description(std::move(description)) {}
    virtual ~JokerCard() = default;

    virtual std::string getName() const { return name; }
    virtual std::string getDescription() const { return description; }

    virtual void onScoreCalculated(ScoreEvent& event) {}
};

#endif // JOKERCARD_H
