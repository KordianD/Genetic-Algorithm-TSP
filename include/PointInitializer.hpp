#pragma once
#include <Path.hpp>

class PointInitializer
{
public:
	virtual ~PointInitializer() = default;
	virtual std::vector<Point> getInitialPoints(int) = 0;

};
