#include <gtest/gtest.h>
#include "RandomPointInitializer.hpp"


namespace
{
    constexpr int LOWER_BOUND{0};
    constexpr int UPPER_BOUND{100};
    constexpr int ZERO_SIZE_OF_SOLUTION{0};
    constexpr int SIZE_OF_SOLUTION{10};
}

using namespace ::testing;

TEST(RandomPointInitializerTestSuite, ShouldReturnEmptySolutionWhenSizeOfSolutionIsZero)
{
    RandomPointInitializer sut(LOWER_BOUND, UPPER_BOUND);

    auto initialSolution = sut.getInitialPoints(ZERO_SIZE_OF_SOLUTION);

    ASSERT_TRUE(initialSolution.empty());
}


TEST(RandomPointInitializerTestSuite, ShouldReturnCorrectlyInitializedSolution)
{
    RandomPointInitializer sut(LOWER_BOUND, UPPER_BOUND);

    auto initialSolution = sut.getInitialPoints(SIZE_OF_SOLUTION);

    EXPECT_EQ(initialSolution.size(), SIZE_OF_SOLUTION);
}
