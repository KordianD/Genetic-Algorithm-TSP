#pragma once
#include <random>
#include <algorithm>

class Initializer
{
public:
    Initializer(int lowerBound, int upperBound);
    int getNumber();
 
private:
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> rand {};
};