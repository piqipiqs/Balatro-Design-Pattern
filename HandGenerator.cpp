#include <iostream>
#include "HandGenerator.h"
Hand HandGenerator::generateHand() {
    Hand h; h.value = 7;
    std::cout << "Generating hand...\n";
    return h;
}