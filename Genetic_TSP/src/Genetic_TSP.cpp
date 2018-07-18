#include <vector>
#include "PointInitializer.hpp"
#include "Population.hpp"


#include <iostream>
int main()
{
    int sizeOfImage = 800;
    int numberOfPoints = 100;
    int sizeOfPopulation = 100;

    PointInitializer initializer(1, sizeOfImage);

    Population population(sizeOfPopulation, numberOfPoints, initializer);

    return(0);
}
