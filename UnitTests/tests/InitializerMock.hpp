#include "gmock/gmock.h"
#include "Initializer.hpp"

class InitializerMock : public Initializer
{
public:

  MOCK_METHOD0(getNumber, double());

};
