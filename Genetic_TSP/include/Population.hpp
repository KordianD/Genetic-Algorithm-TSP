#pragma once

#include "Path.hpp"

class Population
{
public:
    Population(int, int, Initializer&);

private:
    std::vector<Path> population;
    int sizeOfPopulation;
};
