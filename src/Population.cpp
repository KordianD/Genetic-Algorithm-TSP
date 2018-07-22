#include "Population.hpp"
#include <algorithm>
#include <random>
#include <numeric>
#include <stdexcept>
#include <iterator>

Population::Population(int sizeOfPopulation, int sizeOfSolution, std::shared_ptr<PointInitializer> initializer) : sizeOfPopulation(sizeOfPopulation), sizeOfSolution(sizeOfSolution), initializer(initializer)
{
	if (sizeOfPopulation <= 0)
	{
		throw std::invalid_argument("sizeOfPopulation must be greater than 0");
	}

	population.reserve(sizeOfPopulation);
	createAllInitialSolutions();
}


void Population::createAllInitialSolutions()
{
	auto rng = std::default_random_engine {};
	std::vector<Point> initialSolution = initializer->getInitialSolution(sizeOfSolution);

	for (auto i = 0; i < sizeOfPopulation; ++i)
	{
		std::shuffle(std::begin(initialSolution), std::end(initialSolution), rng);
		population.emplace_back(initialSolution);
	}
}

int Population::getRandomNumberInRange(int lowerBound, int upperBound)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(lowerBound, upperBound);

	return distr(eng);
}

Path Population::performTournamentSelection()
{
	auto firstRandomNumber = getRandomNumberInRange(0, population.size() - 1);
	auto secondRandomNumber = getRandomNumberInRange(0, population.size() - 1);

	return population[firstRandomNumber].getFitness() < population[secondRandomNumber].getFitness() ? population[firstRandomNumber] : population[secondRandomNumber];
}


void Population::addBestPathsFromPreviousPopulationToNextPopulation(std::vector<Path>& newPopulation, int howManyPathFromOldPopulationToAdd)
{
	std::vector<Path> temp = population;
	std::sort(std::begin(temp), std::end(temp), [](const auto& lhs, const auto& rhs)
			{ return lhs.getFitness() > rhs.getFitness(); });

	std::copy(std::begin(population), std::begin(population) + howManyPathFromOldPopulationToAdd, std::back_inserter(newPopulation));
}

void Population::mutation()
{
	for (auto& elem : population)
	{
		elem.mutate(getRandomNumberInRange(1, sizeOfSolution-1), getRandomNumberInRange(1, sizeOfSolution-1));
	}
}

void Population::updatePopulation()
{
	std::vector<Path> newPopulation;
	newPopulation.reserve(sizeOfSolution);
	auto percentageOfChildenFromPreviousGeneration = 0.9;
	int numberOfChildrenFromParents = int (sizeOfPopulation * percentageOfChildenFromPreviousGeneration)/2;

	for (auto i = 0; i < numberOfChildrenFromParents; ++i)
	{
		Path firstParent = performTournamentSelection();
		Path secondParent = performTournamentSelection();

		newPopulation.emplace_back(firstParent.crossover(secondParent));
		newPopulation.emplace_back(secondParent.crossover(firstParent));
	}

	addBestPathsFromPreviousPopulationToNextPopulation(newPopulation, sizeOfPopulation - numberOfChildrenFromParents*2);

	population = newPopulation;

	mutation();
}