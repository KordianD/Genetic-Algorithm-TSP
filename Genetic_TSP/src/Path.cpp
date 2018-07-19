#include "Path.hpp"
#include "Initializer.hpp"
#include <cmath>
#include <stdexcept>

Path::Path(int numberOfPoints, std::shared_ptr<Initializer> initializer) : initializer(initializer)
{
	if (numberOfPoints <= 0)
	{
		throw std::invalid_argument("numberOfPoints must be greater than 0");
	}

	path.reserve(numberOfPoints);
    for(auto i = 0; i < numberOfPoints; ++i)
    {
        path.emplace_back(initializer->getNumber(), initializer->getNumber());
    }

    path.emplace_back(path[0].x, path[0].y);

    this->numberOfPoints = path.size();
    fitness = calculateFitness();
}

double Path::getFitness() const
{
	return fitness;
}

double Path::calculateFitness() const
{
    auto sum = 0.0;

    for (auto i = 0; i < numberOfPoints-1; ++i)
    {
        sum += pow(path[i].x - path[i+1].x, 2.0) + pow(path[i].y - path[i+1].y, 2.0);
    }

    return sum;
}
