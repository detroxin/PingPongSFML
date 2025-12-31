#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() 
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    m_engine.seed(seed);
}

int RandomGenerator::getNextRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    
    return distribution(m_engine);
}