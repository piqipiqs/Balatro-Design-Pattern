#ifndef JOKERMANAGER_H
#define JOKERMANAGER_H

#include <vector>
#include <memory>
#include "JokerCard.h"
#include "ScoreEvent.h"

class JokerManager {
public:
    void addJoker(std::unique_ptr<IJokerCard> joker);
    void notifyAll(ScoreEvent& event);
    void applyAll();

private:
    std::vector<std::unique_ptr<IJokerCard>> jokers;
};

#endif // JOKERMANAGER_H