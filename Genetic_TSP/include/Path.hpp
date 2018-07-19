#pragma once

#include "Initializer.hpp"
#include "Point.hpp"
#include <vector>
#include <memory>


class Path
{
public:
    Path(int, std::shared_ptr<Initializer>);
    double getFitness() const;
    double calculateFitness() const;

private:
    std::vector<Point> path;
    std::shared_ptr<Initializer> initializer;
    int numberOfPoints {};
    double fitness {};
};
