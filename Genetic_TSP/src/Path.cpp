#include "Path.hpp"
#include "Initializer.hpp"
#include <cmath>
#include <stdexcept>

Path::Path(std::vector<Point> path) : path(std::move(path))
{
	if (this->path.size() <= 1)
	{
		throw std::invalid_argument("Number of points in Path should be greater than 1");
	}

    fitness = calculateFitness();
}

double Path::getFitness() const
{
	return fitness;
}

double Path::calculateFitness() const
{
    auto sum = 0.0;
    auto numberOfPoints = path.size();

    for (size_t i = 0; i < numberOfPoints-1; ++i)
    {
        sum += pow(path[i].x - path[i+1].x, 2.0) + pow(path[i].y - path[i+1].y, 2.0);
    }

    return sum;
}
