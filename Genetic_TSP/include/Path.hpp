#pragma once

#include "Initializer.hpp"
#include <vector>

struct Point
{
	Point(int x, int y) : x(x), y(y) {}
	int x=0;
	int y=0;
};

struct Path
{
public:
    Path(int, Initializer&);
    double calculateFitness() const;

private:
    std::vector<Point> path;
    Initializer& initializer;
    int numberOfPoints;
};
