#pragma once

#include "gmock/gmock.h"
#include "PointInitializer.hpp"
#include <vector>

class PointInitializerMock : public PointInitializer
{
public:

  MOCK_METHOD1(getInitialSolution, std::vector<Point>(int));

};
