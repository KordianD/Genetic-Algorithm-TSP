#include <vector>
#include "PointInitializer.hpp"
#include "Population.hpp"


int main()
{
    int sizeOfImage = 800;
    int numberOfPoints = 100;
    int sizeOfPopulation = 100;

    std::shared_ptr<Initializer> initializer = std::make_shared<PointInitializer>(1, sizeOfImage);

    Population population(sizeOfPopulation, numberOfPoints, initializer);

    return(0);
}
