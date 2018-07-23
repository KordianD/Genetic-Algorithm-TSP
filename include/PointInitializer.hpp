#pragma once
#include <Path.hpp>

class PointInitializer
{
public:
	virtual ~PointInitializer() = default;
	virtual std::vector<Point> getInitialSolution(int) = 0;
	//TODO: Rename getInitialSolution to getInitialPoints
};
