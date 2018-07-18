#include <gtest/gtest.h>
#include <memory>
#include "Path.hpp"
#include "InitializerMock.hpp"


namespace
{
  constexpr int NO_POINTS = 0;
  constexpr int NUMBER_OF_POINTS = 3;
  constexpr double FITNESS = 160000;
}

using namespace ::testing;

TEST(PathTestSuite, ShouldReturnZeroWhenThereAreNoPoints)
{
  std::shared_ptr<Initializer> initializerMock = std::make_shared<StrictMock<InitializerMock>>();
  Path sut(NO_POINTS, *initializerMock);

  EXPECT_EQ(sut.calculateFitness(), NO_POINTS);

}

TEST(PathTestSuite, ShouldReturnCorrectValueWhenCorrectDataPassed)
{
  std::shared_ptr<InitializerMock> initializerMock = std::make_shared<NiceMock<InitializerMock>>();

  auto callCount = 0;
  ON_CALL(*initializerMock, getNumber())
      .WillByDefault(testing::Invoke(
          [&callCount](){
              return ++callCount*100;
          }
      ));

  Path sut(NUMBER_OF_POINTS, *initializerMock);

  EXPECT_EQ(sut.calculateFitness(), FITNESS);
}
