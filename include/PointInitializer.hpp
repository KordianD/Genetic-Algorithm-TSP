#pragma once
#include <Path.hpp>

class PointInitializer
{
public:
	virtual ~PointInitializer() = default;
	virtual std::vector<Point> getInitialSolution(int) = 0;
};
