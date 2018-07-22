#include <gtest/gtest.h>
#include "Point.hpp"

namespace
{
  constexpr int X_COORDINATE {5};
  constexpr int Y_COORDINATE {100};
}

using namespace ::testing;

TEST(PointTestSuite, ShouldReturnTrueWhenComparingTheSamePoints)
{
  Point first(X_COORDINATE, Y_COORDINATE);
  Point second(X_COORDINATE, Y_COORDINATE);

  EXPECT_TRUE(first == second);
}

TEST(PointTestSuite, ShouldReturnFalseWhenComparingDifferentPoints)
{
  Point first(X_COORDINATE, Y_COORDINATE);
  Point second;

  EXPECT_FALSE(first == second);
}
