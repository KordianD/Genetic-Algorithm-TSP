#include "PointInitializer.hpp"
#include <random>
#include <algorithm>

PointInitializer::PointInitializer(int lowerBound, int upperBound) : rand(lowerBound, upperBound)
{
    rng.seed(std::random_device()());
}

double PointInitializer::getNumber()
{
    return rand(rng);
}
