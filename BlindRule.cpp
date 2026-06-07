#include "BlindRule.h"

BlindRule::BlindRule(int target)
    : target(target) {}

int BlindRule::getTarget() const {
    return target;
}

bool BlindRule::isDefeated(int score) const {
    return score >= target;
}
