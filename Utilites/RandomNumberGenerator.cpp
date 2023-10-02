//
// Created by hakkerboi on 9/29/23.
//

#include <random>
#include "RandomNumberGenerator.hpp"

int RandomNumberGenerator::getRandomNumber() {
    srand(std::random_device()());
    return rand();
}
