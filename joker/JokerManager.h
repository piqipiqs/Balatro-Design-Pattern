#ifndef JOKERMANAGER_H
#define JOKERMANAGER_H

#include <vector>
#include <memory>
#include "JokerCard.h"
#include "../ScoreEvent.h"

class JokerManager {
public:
    void addJoker(std::unique_ptr<JokerCard> joker);
    void notifyAll(ScoreEvent& event);

private:
    std::vector<std::unique_ptr<JokerCard>> jokers;
};

#endif // JOKERMANAGER_H
