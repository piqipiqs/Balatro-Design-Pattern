#include "GameManager.h"
#include "joker/PairJoker.h"
#include "joker/FlatChipJoker.h"
#include "joker/FlushJoker.h"
#include "joker/HeartJoker.h"
#include "joker/FaceCardJoker.h"

int main() {
    GameManager gm;
    gm.addJoker(std::make_unique<PairJoker>());
    gm.addJoker(std::make_unique<FlatChipJoker>());
    gm.addJoker(std::make_unique<FlushJoker>());
    gm.addJoker(std::make_unique<HeartJoker>());
    gm.addJoker(std::make_unique<FaceCardJoker>());

    gm.run(300);

    return 0;
}
