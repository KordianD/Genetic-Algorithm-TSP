#include <PointInitializer.hpp>
#include <cmath>
#include <algorithm>

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

std::vector<Point> Path::getPath() const
{
    return path;
}

void Path::mutate(int lowerBound, int upperBound)
{
    std::swap(path[lowerBound], path[upperBound]);
}

std::vector<Point> Path::crossover(const Path &parent) const
{
    std::vector<Point> child;
    child.reserve(path.size());
    int halfOfSize = path.size() / 2;

    std::copy_n(std::begin(path), halfOfSize, std::back_inserter(child));

    for (auto const &elem : parent.path)
    {
        if (std::find(child.begin(), child.end(), elem) == child.end())
        {
            child.emplace_back(elem);
        }
    }

    child.emplace_back(path[0]);

    return child;
}

double Path::calculateFitness() const
{
    auto sum = 0.0;

    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        sum += sqrt(pow(path[i].x - path[i + 1].x, 2.0) + pow(path[i].y - path[i + 1].y, 2.0));
    }

    return sum;
}
