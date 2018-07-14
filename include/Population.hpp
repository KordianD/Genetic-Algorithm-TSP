#pragma once

#include <vector>
#include "Path.hpp"

class Initializer;

class Population
{
public:
    Population(int, int, const Initializer&);

private:
    std::vector<Path> population;
    int sizeOfPopulation;
};   