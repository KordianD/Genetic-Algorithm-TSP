#pragma once

#include "Path.hpp"

class Population
{
public:
    Population(int, int, std::shared_ptr<PointInitializer>);
    void performSelection(double);
    int getRandomNumberInRange(int, int);
    Path performTournamentSelection();
    void mutation();
    void addBestPathsFromPreviousPopulationToNextPopulation(std::vector<Path>&, int);
    void updatePopulation();


private:
    void createAllInitialSolutions();
    std::vector<Path> population;
    int sizeOfPopulation;
    int sizeOfSolution;
    std::shared_ptr<PointInitializer> initializer;
};
