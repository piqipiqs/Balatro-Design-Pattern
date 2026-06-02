#ifndef JOKER_CARD_H
#define JOKER_CARD_H

#include <string>
#include <utility>
#include "ScoreEvent.h"

class IJokerCard {
private:
    std::string name;
    std::string description;

public:
    IJokerCard(std::string name, std::string description) 
        : name(std::move(name)), description(std::move(description)) {}
    virtual ~IJokerCard() = default;

    virtual std::string getName() const { return name; }
    virtual std::string getDescription() const { return description; }

    // Observer pattern update method
    virtual void update(ScoreEvent& event) = 0;

  
};

#endif // JOKER_CARD_H
