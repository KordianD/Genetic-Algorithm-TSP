#include <FilePointInitializer.hpp>
#include "Population.hpp"
#include <iostream>
#include <algorithm>
#include <Plotter.hpp>
#include <RandomPointInitializer.hpp>


int main()
{
    auto imageWidth = 1700;
    auto imageHeight = 1000;
    auto numberOfPoints = 50;
    auto sizeOfPopulation = 500;
    auto numberOfIteration = 1000;
    auto mutationRate = 0.05;

    std::shared_ptr<PointInitializer> initializer = std::make_shared<RandomPointInitializer>(imageHeight, imageWidth);
    //std::shared_ptr<PointInitializer> initializer = std::make_shared<FilePointInitializer>("../tests/test.txt");

    Population population(sizeOfPopulation, numberOfPoints, mutationRate, initializer);
    population.runAlgorithm(numberOfIteration);

    auto result = population.getBestSolutionPath();
    std::cout << "FOUND FITNESS " << population.getBestSolutionFitness() << std::endl;

    for (const auto& elem : result)
    {
        std::cout << elem.x << " " << elem.y << std::endl;
    }

    Plotter plotter(imageHeight, imageWidth);
    plotter.drawPoints(result);

    return(0);
}
