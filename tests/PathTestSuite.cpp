#include "gmock/gmock.h"
#include "Path.hpp"

class PathTestSuite : public Path {
 public:

  MOCK_CONST_METHOD0(calculateFitness, double());

};
