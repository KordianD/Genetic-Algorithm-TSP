#include "Population.hpp"

Population::Population(int sizeOfPopulation, int numberOfPoints, const Initializer& initializer)
{
    population.reserve(sizeOfPopulation);
    for (auto i = 0; i < sizeOfPopulation; ++i)
    {
        population.emplace_back(numberOfPoints, initializer);
    }
}