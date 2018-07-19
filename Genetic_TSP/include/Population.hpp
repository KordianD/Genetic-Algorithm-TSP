#pragma once

#include "Path.hpp"

class Population
{
public:
    Population(int, int, std::shared_ptr<Initializer>);
    void performSelection(double);

private:
    std::vector<Path> population;
    int sizeOfPopulation;
};
