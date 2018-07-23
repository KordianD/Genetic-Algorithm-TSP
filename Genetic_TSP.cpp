#include <FilePointInitializer.hpp>
#include "Population.hpp"
#include <iostream>


int main()
{
    auto numberOfPoints = 7;
    auto sizeOfPopulation = 1000;
    auto numberOfIteration = 1000;

    std::shared_ptr<PointInitializer> initializer = std::make_shared<FilePointInitializer>("../test.txt");

    Population population(sizeOfPopulation, numberOfPoints, initializer);
    population.runAlgorithm(numberOfIteration);

    auto result = population.getBestSolution().getPath();

    for (auto elem : result)
    {
        std::cout << elem.x << " " << elem.y << std::endl;
    }

    std::cout << "elo" << std::endl;
    return(0);
}
