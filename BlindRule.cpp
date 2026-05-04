#include <iostream>
#include "BlindRule.h"
bool BlindRule::checkBlind(int score) {
    std::cout << "Checking...\n";
    return score >= 5;
}