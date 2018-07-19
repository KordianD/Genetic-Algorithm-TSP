#include "Population.hpp"
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stdexcept>

Population::Population(int sizeOfPopulation, int numberOfPoints, std::shared_ptr<Initializer> initializer) : sizeOfPopulation(sizeOfPopulation)
{
	if (sizeOfPopulation <= 0)
	{
		throw std::invalid_argument("sizeOfPopulation must be greater than 0");
	}

    population.reserve(sizeOfPopulation);
    for (auto i = 0; i < sizeOfPopulation; ++i)
    {
        population.emplace_back(numberOfPoints, initializer);
    }
}

void Population::performSelection(double percentageOfAllPopulation)
{
	std::sort(std::begin(population), std::end(population), [](const auto& lhs, const auto& rhs)
			{ return lhs.getFitness() > rhs.getFitness(); });

	auto sum = 0.0;
	for (const auto& elem : population)
	{
		sum += elem.getFitness();
	}


	std::vector<int> map(population.size());

	auto size = population.size();
	//map[0] = population[0];

    for (auto i = 1; i < size; ++i)
    {
    	;
    }


}
