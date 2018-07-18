#pragma once

#include "Initializer.hpp"
#include "Point.hpp"
#include <vector>


class Path
{
public:
    Path(int, Initializer&);
    double calculateFitness() const;

private:
    std::vector<Point> path;
    Initializer& initializer;
    int numberOfPoints;
};
