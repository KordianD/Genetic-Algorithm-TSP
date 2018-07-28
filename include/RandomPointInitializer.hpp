#pragma once

#include <random>
#include <algorithm>

#include "PointInitializer.hpp"

class RandomPointInitializer : public PointInitializer
{
public:
    RandomPointInitializer(int, int);

    std::vector<Point> getInitialPoints(int) override;

private:
    std::mt19937 rng{};
    std::uniform_int_distribution<std::mt19937::result_type> randX{};
    std::uniform_int_distribution<std::mt19937::result_type> randY{};
};
