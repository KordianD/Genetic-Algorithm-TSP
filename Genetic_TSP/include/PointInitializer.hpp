#pragma once

#include <random>
#include <algorithm>
#include "Initializer.hpp"

class PointInitializer : public Initializer
{
public:
	PointInitializer(int, int);
	double getNumber() override;
private:
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> rand {};
};
