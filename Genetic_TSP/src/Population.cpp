#include "Population.hpp"
#include <algorithm>
#include <numeric>
#include <stdexcept>

Population::Population(int sizeOfPopulation, int numberOfPoints, std::shared_ptr<Initializer> initializer) : sizeOfPopulation(sizeOfPopulation)
{
	if (sizeOfPopulation <= 0)
	{
		throw std::invalid_argument("sizeOfPopulation must be greater than 0");
	}

    population.reserve(sizeOfPopulation);
//    for (auto i = 0; i < sizeOfPopulation; ++i)
//    {
//        population.emplace_back(numberOfPoints, initializer);
//    }
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

}

//Path Population::performTournamentSelection()
//{
//	// current = random initialize
//	// numberOfPaths = population.size();
//	// for (auto i = 0; i < k; ++i)
//	//{
//		 // if (population[randomNumber] > current)
//         	//{
//         		 //current = population[randomNumber];
//         	//}
//	//}
//}
