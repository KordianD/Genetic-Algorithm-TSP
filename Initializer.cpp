#include "Initializer.hpp"

Initializer::Initializer(int lowerBound, int upperBound) : rand(lowerBound, upperBound) 
{
    rng.seed(std::random_device()());
}

int Initializer::getNumber()
{
    return rand(rng);
}
