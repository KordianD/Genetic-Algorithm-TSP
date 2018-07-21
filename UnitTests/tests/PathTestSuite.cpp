#include <gtest/gtest.h>
#include "Path.hpp"
#include <stdexcept>

namespace
{
  constexpr int ZERO_FITNESS {0};
  constexpr double FITNESS {48};
  const std::vector<Point> EMPTY_PATH {};
  const std::vector<Point> PATH {{1,2}, {3,4}, {5,6}, {1,2}};
  const std::vector<Point> THE_SAME_PATH {{5,5}, {5,5}};
}

using namespace ::testing;

TEST(PathTestSuite, ShouldThrowExceptionWhenThereAreNoPoints)
{
  EXPECT_THROW((Path(EMPTY_PATH)), std::invalid_argument);
}

TEST(PathTestSuite, ShouldReturnZeroFitnessWhenThereAreTheseSamePoints)
{
  Path sut(THE_SAME_PATH);

  EXPECT_EQ(sut.getFitness(), ZERO_FITNESS);
  EXPECT_EQ(sut.calculateFitness(), ZERO_FITNESS);
}

TEST(PathTestSuite, ShouldReturnCorrectValueWhenCorrectDataPassed)
{
  Path sut(PATH);

  EXPECT_EQ(sut.getFitness(), FITNESS);
  EXPECT_EQ(sut.calculateFitness(), FITNESS);
}
