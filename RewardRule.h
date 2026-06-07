#ifndef REWARDRULE_H
#define REWARDRULE_H

class RewardRule {
public:
    // Returns total money earned after clearing a blind
    // base reward + $1 per remaining hand
    int earnMoney(int baseReward, int remainingHands);
};

#endif
