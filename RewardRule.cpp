#include "RewardRule.h"
#include <iostream>

int RewardRule::earnMoney(int baseReward, int remainingHands) {
    int total = baseReward + remainingHands;
    std::cout << "Reward: $" << baseReward << " base + $" << remainingHands
              << " (" << remainingHands << " hands remaining) = $" << total << "\n";
    return total;
}
