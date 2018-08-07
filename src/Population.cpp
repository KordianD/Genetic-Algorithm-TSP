#include "Population.hpp"
#include <algorithm>
#include <iterator>
#include <Population.hpp>


Population::Population(const GeneticAlgorithmParameters &geneticAlgorithmParameters,
                       std::shared_ptr<PointInitializer> initializer) :
        geneticAlgorithmParameters(geneticAlgorithmParameters),
        initializer(std::move(initializer))
{
    if (geneticAlgorithmParameters.sizeOfPopulation <= 0)
    {
        throw std::invalid_argument("sizeOfPopulation must be greater than 0");
    }

    population.reserve(geneticAlgorithmParameters.sizeOfPopulation);
    historyOfLearning.reserve(geneticAlgorithmParameters.numberOfIterations);
    createAllInitialSolutions();
    bestSolution = getBestSolutionInCurrentPopulation();
    saveActualScore(getBestSolutionFitness());
}

Path Population::getBestSolutionInCurrentPopulation() const
{
    return *std::min_element(population.begin(),
                             population.end(),
                             [](const auto &lhs, const auto &rhs)
                             {
                                 return lhs.getFitness() < rhs.getFitness();
                             });

}

void Population::runAlgorithm()
{
    for (auto i = 0; i < geneticAlgorithmParameters.numberOfIterations; ++i)
    {
        updatePopulation();
    }
}

void Population::createAllInitialSolutions()
{
    auto rng = std::default_random_engine{};
    std::vector<Point> initialSolution = initializer->getInitialPoints(geneticAlgorithmParameters.numberOfPoints);

    for (auto i = 0; i < geneticAlgorithmParameters.sizeOfPopulation; ++i)
    {
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

    return std::min(population[firstRandomNumber], population[secondRandomNumber], [](const auto &lhs, const auto &rhs)
    { return lhs.getFitness() < rhs.getFitness(); });
}


void Population::addBestPathsFromPreviousPopulationToNextPopulation(std::vector<Path> &newPopulation,
                                                                    int howManyPathFromOldPopulationToAdd) const
{
    std::vector<Path> temp = population;
    std::sort(std::begin(temp), std::end(temp), [](const auto &lhs, const auto &rhs)
    { return lhs.getFitness() > rhs.getFitness(); });

    std::copy_n(std::begin(population), howManyPathFromOldPopulationToAdd, std::back_inserter(newPopulation));
}

void Population::mutation()
{
    for (auto &elem : population)
    {
        if (getRandomNumberInRange(0, 1) < geneticAlgorithmParameters.mutationRate)
        {
            elem.mutate(getRandomNumberInRange(1, geneticAlgorithmParameters.numberOfPoints - 1),
                        getRandomNumberInRange(1, geneticAlgorithmParameters.numberOfPoints - 1));
        }
    }
}

void Population::updatePopulation()
{
    std::vector<Path> newPopulation;
    newPopulation.reserve(geneticAlgorithmParameters.numberOfPoints);
    auto percentageOfChildrenFromPreviousGeneration = 0.9;
    int numberOfChildrenFromParents =
            int(geneticAlgorithmParameters.sizeOfPopulation * percentageOfChildrenFromPreviousGeneration) / 2;

    for (auto i = 0; i < numberOfChildrenFromParents; ++i)
    {
        Path firstParent = performTournamentSelection();
        Path secondParent = performTournamentSelection();

        newPopulation.emplace_back(firstParent.crossover(secondParent));
        newPopulation.emplace_back(secondParent.crossover(firstParent));
    }

    addBestPathsFromPreviousPopulationToNextPopulation(newPopulation, geneticAlgorithmParameters.sizeOfPopulation -
                                                                      numberOfChildrenFromParents * 2);

    population = newPopulation;

    mutation();
    checkForBetterSolution();
}

void Population::checkForBetterSolution()
{
    auto bestSolutionInCurrentPopulation = getBestSolutionInCurrentPopulation();
    saveActualScore(bestSolutionInCurrentPopulation.getFitness());
    if (bestSolutionInCurrentPopulation.getFitness() < bestSolution->getFitness())
    {
        bestSolution = bestSolutionInCurrentPopulation;
        bestSolutionNumber = historyOfLearning.size();
    }
}

std::vector<Point> Population::getBestSolutionPath() const
{
    return bestSolution->getPath();
}

double Population::getBestSolutionFitness() const
{
    return bestSolution->getFitness();
}

std::vector<double> Population::getHistoryOfLearning() const
{
    return historyOfLearning;
}

void Population::saveActualScore(double bestSolution)
{
    historyOfLearning.emplace_back(bestSolution);
}

int Population::getNumberOfBestSolution() const
{
    return bestSolutionNumber;
}
