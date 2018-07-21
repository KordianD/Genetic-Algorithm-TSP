#pragma once

#include "Initializer.hpp"
#include "Point.hpp"
#include <vector>
#include <memory>


class Path
{
public:
    Path(std::vector<Point>);
    double getFitness() const;
    double calculateFitness() const;

private:
    std::vector<Point> path;
    double fitness {};
};
