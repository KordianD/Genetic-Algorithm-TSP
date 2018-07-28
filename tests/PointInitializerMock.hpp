#pragma once

#include "gmock/gmock.h"
#include "PointInitializer.hpp"
#include <vector>

class PointInitializerMock : public PointInitializer
{
public:

  MOCK_METHOD1(getInitialPoints, std::vector<Point>(int));

};
