#pragma once

#include "Point.hpp"
#include <vector>
#include <memory>
#include "PointInitializer.hpp"


class Path
{
public:
    Path(std::vector<Point>);
    double getFitness() const;
    double calculateFitness() const;
    std::vector<Point> getPath();
    void mutate(int, int);
    std::vector<Point> crossover(const Path& parent);

private:
    std::vector<Point> path;
    double fitness {};
};
