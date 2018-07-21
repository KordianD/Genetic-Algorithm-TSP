#include <vector>
#include "PointInitializer.hpp"
#include "Population.hpp"

#include <random>
#include <iostream>
int main()
{
       int sizeOfImage = 800;
//    int numberOfPoints = 100;
//    int sizeOfPopulation = 100;
//
     std::shared_ptr<Initializer> initializer = std::make_shared<PointInitializer>(1, sizeOfImage);
//
//    Population population(sizeOfPopulation, numberOfPoints, initializer);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(25, 63); // define the range

    for(int n=0; n<40; ++n)
        std::cout << initializer->getNumber() << ' '; // generate numbers

    return(0);
}
