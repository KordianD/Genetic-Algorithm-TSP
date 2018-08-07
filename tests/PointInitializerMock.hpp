#ifndef TSP_FINAL_POINTINITIALIZERMOCK_HPP
#define TSP_FINAL_POINTINITIALIZERMOCK_HPP

#include "gmock/gmock.h"
#include "PointInitializer.hpp"
#include <vector>

class PointInitializerMock : public PointInitializer
{
public:

    MOCK_METHOD1(getInitialPoints, std::vector<Point>(int));

};

#endif
