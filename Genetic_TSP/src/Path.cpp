#include "Path.hpp"
#include "Initializer.hpp"
#include <cmath>

Path::Path(int numberOfPoints, Initializer& initializer) : initializer(initializer), numberOfPoints(numberOfPoints)
{
    for(auto i = 0; i < numberOfPoints; ++i)
    {
        path.emplace_back(initializer.getNumber(), initializer.getNumber());
    }
}

double Path::calculateFitness() const
{
    auto sum = 0.0;

    for (auto i = 0; i < numberOfPoints; ++i)
    {
        sum += pow(path[i].x - path[i+1].x, 2.0) + pow(path[i].y - path[i+1].y, 2.0);
    }

    return sum;
}
