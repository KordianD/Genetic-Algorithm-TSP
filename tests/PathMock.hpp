#include "gmock/gmock.h"
#include "Path.hpp"

class PathMock : public Path {
 public:

  MOCK_CONST_METHOD0(calculateFitness, double());

};
