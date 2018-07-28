#include <gtest/gtest.h>
#include "Path.hpp"

namespace
{
  constexpr int ZERO_FITNESS {0};
  constexpr double FITNESS {4};
  constexpr int FIRST_INDEX_TO_MUTATE {1};
  constexpr int SECOND_INDEX_TO_MUTATE {2};
  const std::vector<Point> EMPTY_PATH {};
  const std::vector<Point> SIMPLE_PATH {{1,1}, {2,1}, {2,0}, {1,0}, {1,1}};
  const std::vector<Point> PATH {{1,2}, {3,4}, {5,6}, {7,8}, {1,2}};
  const std::vector<Point> MUTATE_PATH {{5,6}, {1,2}, {3,4}, {7,8}, {5,6}};
  const std::vector<Point> THE_SAME_PATH {{5,5}, {5,5}};
  const Path PATH_TO_CROSSOVER {MUTATE_PATH};
  const std::vector<Point> AFTER_CROSSOVER_PATH {{1,2}, {3,4}, {5,6}, {7,8}, {1,2}};
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
  Path sut(SIMPLE_PATH);

  EXPECT_EQ(sut.getFitness(), FITNESS);
  EXPECT_EQ(sut.calculateFitness(), FITNESS);
}

TEST(PathTestSuite, ShouldReturnPathWithSwappedIndexes)
{
  Path sut(PATH);

  sut.mutate(FIRST_INDEX_TO_MUTATE, SECOND_INDEX_TO_MUTATE);
  auto mutatedPath = sut.getPath();

  EXPECT_EQ(mutatedPath[FIRST_INDEX_TO_MUTATE], PATH[SECOND_INDEX_TO_MUTATE]);
  EXPECT_EQ(mutatedPath[SECOND_INDEX_TO_MUTATE], PATH[FIRST_INDEX_TO_MUTATE]);
}

TEST(PathTestSuite, ShouldMakeCrossoverAndReturnCrossedPoints)
{
  Path sut(PATH);

  auto mutatedPath = sut.crossover(PATH_TO_CROSSOVER);

  EXPECT_EQ(mutatedPath, AFTER_CROSSOVER_PATH);
  EXPECT_EQ(mutatedPath.size(), PATH.size());
}






