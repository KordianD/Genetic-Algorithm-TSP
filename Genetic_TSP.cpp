#include <RandomPointInitializer.hpp>
#include <vector>
#include "Population.hpp"

#include <random>
#include <iostream>
int main()
{
     int sizeOfImage = 800;
//    int numberOfPoints = 100;
//    int sizeOfPopulation = 100;
//
    std::shared_ptr<PointInitializer> initializer = std::make_shared<RandomPointInitializer>(1, sizeOfImage);
//
//    Population population(sizeOfPopulation, numberOfPoints, initializer);

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(25, 63);

    std::cout << "elo" << std::endl;
    return(0);
}
