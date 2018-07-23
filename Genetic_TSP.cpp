#include <FilePointInitializer.hpp>
#include "Population.hpp"
#include <iostream>


int main()
{
    auto numberOfPoints = 7;
    auto sizeOfPopulation = 100;
    auto numberOfIteration = 100;

    std::shared_ptr<PointInitializer> initializer = std::make_shared<FilePointInitializer>("../test.txt");

    Population population(sizeOfPopulation, numberOfPoints, initializer);
    population.runAlgorithm(numberOfIteration);

    auto result = population.getBestSolution().getPath();

    for (auto elem : result)
    {
        std::cout << elem.x << " " << elem.y << std::endl;
    }

    return(0);
}
