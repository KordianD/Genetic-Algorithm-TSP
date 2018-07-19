#include <gtest/gtest.h>
#include <memory>
#include "Path.hpp"
#include "InitializerMock.hpp"
#include <stdexcept>


namespace
{
  constexpr int ZERO_FITNESS {0};
  constexpr int NO_POINTS {0};
  constexpr int NUMBER_OF_POINTS {3};
  constexpr double FITNESS {48};
}

using namespace ::testing;

TEST(PathTestSuite, ShouldThrowExceptionWhenThereAreNoPoints)
{
  std::shared_ptr<Initializer> initializerMock = std::make_shared<StrictMock<InitializerMock>>();

  EXPECT_THROW((Path{NO_POINTS, initializerMock}), std::invalid_argument);

}

TEST(PathTestSuite, ShouldReturnCorrectValueWhenCorrectDataPassed)
{
  std::shared_ptr<InitializerMock> initializerMock = std::make_shared<NiceMock<InitializerMock>>();

  auto callCount = 0;
  ON_CALL(*initializerMock, getNumber())
      .WillByDefault(Invoke(
          [&callCount](){
              return ++callCount;
          }
      ));

  Path sut(NUMBER_OF_POINTS, initializerMock);

  EXPECT_EQ(sut.getFitness(), FITNESS);
  EXPECT_EQ(sut.calculateFitness(), FITNESS);
}
