#include <iostream>
#include "RewardRule.h"
int RewardRule::earnMoney(bool win, int score) {
    std::cout << "Reward...\n";
    return win ? score : 0;
}