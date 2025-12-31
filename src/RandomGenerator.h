#pragma once
#include <random>
#include <chrono>

class RandomGenerator {
private:
    std::mt19937 m_engine;
public:
    RandomGenerator();
    int getNextRandomNumber(int min, int max);
};