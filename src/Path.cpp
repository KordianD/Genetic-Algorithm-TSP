#include "Path.hpp"

Path::Path(int numberOfPoints, Initializer initializer) : initializer(initializer), numberOfPoints(numberOfPoints) 
{
    for(auto i = 0; i < numberOfPoints; ++i)
    {
        path.emplace_back(initializer.getNumber(), initializer.getNumber());
    }
}

auto Path::calculateFitness()
{
    auto sum = 0.0;

    for (auto i = 0; i < numberOfPoints; ++i)
    {
        sum += pow(path[i].x - path[i+1].x, 2) + pow(path[i].y - path[i+1].y, 2);
    }

    return sum;
}
