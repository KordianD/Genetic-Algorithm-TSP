#include <FilePointInitializer.hpp>
#include "Population.hpp"
#include <iostream>
#include <algorithm>


int main()
{
    auto numberOfPoints = 14;
    auto sizeOfPopulation = 150;
    auto numberOfIteration = 10;
    auto mutationRate = 0.1;

    std::shared_ptr<PointInitializer> initializer = std::make_shared<FilePointInitializer>("../tests/test.txt");

    Population population(sizeOfPopulation, numberOfPoints, mutationRate, initializer);
    population.runAlgorithm(numberOfIteration);

    auto result = population.getBestSolutionPath();
    std::cout << "FOUND FITNESS " << population.getBestSolutionFitness() << std::endl;

    for (auto elem : result)
    {
        std::cout << elem.x << " " << elem.y << std::endl;
    }

    return(0);
}
