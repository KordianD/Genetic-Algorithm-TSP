#include "Population.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

Population::Population(int sizeOfPopulation, int sizeOfSolution, double mutationRate, std::shared_ptr<PointInitializer> initializer) :
        sizeOfPopulation(sizeOfPopulation),
        sizeOfSolution(sizeOfSolution),
		mutationRate(mutationRate),
        initializer(std::move(initializer))
{
	if (sizeOfPopulation <= 0)
	{
		throw std::invalid_argument("sizeOfPopulation must be greater than 0");
	}

	population.reserve(sizeOfPopulation);
	createAllInitialSolutions();
	bestSolution = getBestSolutionInCurrentPopulation();

}

Path Population::getBestSolutionInCurrentPopulation()
{
    return *std::min_element(population.begin(),
                      population.end(),
                      [] (const auto& lhs, const auto& rhs) {
                          return lhs.getFitness() < rhs.getFitness();
                      });

}

void Population::runAlgorithm(int numberOfIterations)
{
    for (auto i = 0; i < numberOfIterations; ++i)
    {
        updatePopulation();
    }
}

void Population::createAllInitialSolutions()
{
	auto rng = std::default_random_engine {};
	std::vector<Point> initialSolution = initializer->getInitialPoints(sizeOfSolution);

	for (auto i = 0; i < sizeOfPopulation; ++i) {
        std::shuffle(std::begin(initialSolution), std::end(initialSolution), rng);
        std::vector<Point> temp(initialSolution);
        temp.emplace_back(temp[0]);

        population.emplace_back(temp);
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
	    if (getRandomNumberInRange(0, 1) < mutationRate)
	    {
            elem.mutate(getRandomNumberInRange(1, sizeOfSolution - 1), getRandomNumberInRange(1, sizeOfSolution - 1));
        }
	}
}

void Population::updatePopulation()
{
	std::vector<Path> newPopulation;
	newPopulation.reserve(sizeOfSolution);
	auto percentageOfChildrenFromPreviousGeneration = 0.9;
	int numberOfChildrenFromParents = int (sizeOfPopulation * percentageOfChildrenFromPreviousGeneration)/2;

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
    checkForBetterSolution();
}

void Population::checkForBetterSolution()
{
    auto bestSolutionInCurrentPopulation = getBestSolutionInCurrentPopulation();

    if (bestSolutionInCurrentPopulation.getFitness() < bestSolution->getFitness())
    {
        bestSolution = bestSolutionInCurrentPopulation;
    }
}

std::vector<Point> Population::getBestSolutionPath()
{
	return bestSolution->getPath();
}

double Population::getBestSolutionFitness()
{
	return bestSolution->getFitness();
}