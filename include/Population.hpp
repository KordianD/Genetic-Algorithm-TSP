#pragma once

#include <optional>
#include <random>
#include "Path.hpp"
#include "GeneticAlgorithmParameters.hpp"

class Population
{
public:
    Population(const GeneticAlgorithmParameters&, std::shared_ptr<PointInitializer>);
    int getRandomNumberInRange(int, int);
    Path performTournamentSelection();
    void mutation();
    void addBestPathsFromPreviousPopulationToNextPopulation(std::vector<Path>&, int);
    void updatePopulation();
    std::vector<Point> getBestSolutionPath();
    double getBestSolutionFitness();
    Path getBestSolutionInCurrentPopulation();
    void runAlgorithm(int);

private:
    void createAllInitialSolutions();
    void checkForBetterSolution();

    std::vector<Path> population {};
    GeneticAlgorithmParameters geneticAlgorithmParameters{};
    std::shared_ptr<PointInitializer> initializer {};
    std::optional<Path> bestSolution {};
};
