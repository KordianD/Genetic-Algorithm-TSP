#include <gtest/gtest.h>
#include "Population.hpp"
#include <memory>
#include "PointInitializerMock.hpp"
#include <stdexcept>

namespace
{
  constexpr int SIZE_OF_SOLUTION {100};
  constexpr int SIZE_OF_POPULATION {50};
  constexpr int LOWER_BOUND {20};
  constexpr int UPPER_BOUND {77};
  const std::vector<Point> EMPTY_INITIAL_SOLUTION {};
  const std::vector<Point> INITIAL_SOLUTION {{1,2}, {3,4}};
}

using namespace ::testing;


TEST(PopulationTestSuite, ShouldReturnExceptionWhenInitialSolutionIsEmpty)
{
  std::shared_ptr<PointInitializerMock> initializerMock = std::make_shared<StrictMock<PointInitializerMock>>();
  EXPECT_CALL(*initializerMock, getInitialSolution(_)).WillRepeatedly(Return(EMPTY_INITIAL_SOLUTION));

  EXPECT_THROW((Population(SIZE_OF_POPULATION, SIZE_OF_SOLUTION, initializerMock)), std::invalid_argument);
}

TEST(PopulationTestSuite, ShouldReturnNumberInPassedRange)
{
  std::shared_ptr<PointInitializerMock> initializerMock = std::make_shared<StrictMock<PointInitializerMock>>();
  EXPECT_CALL(*initializerMock, getInitialSolution(_)).WillRepeatedly(Return(INITIAL_SOLUTION));

  Population sut(SIZE_OF_POPULATION, SIZE_OF_SOLUTION, initializerMock);
  auto randomNumber = sut.getRandomNumberInRange(LOWER_BOUND, UPPER_BOUND);

  EXPECT_LE(randomNumber, UPPER_BOUND);
  EXPECT_GE(randomNumber, LOWER_BOUND);
}


