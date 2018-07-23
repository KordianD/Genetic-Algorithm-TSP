#pragma once

#include <optional>
#include "Path.hpp"

class Population
{
public:
    Population(int, int, std::shared_ptr<PointInitializer>);
    int getRandomNumberInRange(int, int);
    Path performTournamentSelection();
    void mutation();
    void addBestPathsFromPreviousPopulationToNextPopulation(std::vector<Path>&, int);
    void updatePopulation();
    Path getBestSolution();
    void runAlgorithm(int);

private:
    void createAllInitialSolutions();
    void checkForBetterSolution();
    std::vector<Path> population;
    int sizeOfPopulation;
    int sizeOfSolution;
    std::shared_ptr<PointInitializer> initializer;
    std::optional<Path> bestSolution {};
};
