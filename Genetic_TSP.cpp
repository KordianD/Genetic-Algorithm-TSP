#include <FilePointInitializer.hpp>
#include "Population.hpp"
#include <iostream>
#include <algorithm>
#include <random>


int main()
{
    auto numberOfPoints = 14;
    auto sizeOfPopulation = 150;
    auto numberOfIteration = 10000;

    std::shared_ptr<PointInitializer> initializer = std::make_shared<FilePointInitializer>("../tests/test.txt");

    Population population(sizeOfPopulation, numberOfPoints, initializer);
    population.runAlgorithm(numberOfIteration);

    auto result = population.getBestSolution().getPath();
    std::cout << "FOUND FITNESS " << population.getBestSolution().getFitness() << std::endl;

    for (auto elem : result)
    {
        std::cout << elem.x << " " << elem.y << std::endl;
    }

    return(0);
}
