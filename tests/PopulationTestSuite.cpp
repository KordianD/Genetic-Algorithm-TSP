#include <gtest/gtest.h>
#include "Population.hpp"
#include "PointInitializerMock.hpp"


namespace
{
    constexpr int NUMBER_OF_POINTS{100};
    constexpr int SIZE_OF_POPULATION{50};
    constexpr int ZERO_SIZE_OF_POPULATION{0};
    constexpr int NUMBER_OF_INTERATIONS {1000};
    constexpr double MUTATION_RATE{0.05};
    constexpr GeneticAlgorithmParameters PARAMETERS{NUMBER_OF_POINTS, SIZE_OF_POPULATION, NUMBER_OF_INTERATIONS, MUTATION_RATE};
    constexpr GeneticAlgorithmParameters INVALID_PARAMETERS{NUMBER_OF_POINTS, ZERO_SIZE_OF_POPULATION, NUMBER_OF_INTERATIONS, MUTATION_RATE};
    constexpr int LOWER_BOUND{20};
    constexpr int UPPER_BOUND{77};
    const std::vector<Point> EMPTY_INITIAL_SOLUTION{};
    const std::vector<Point> INITIAL_SOLUTION{{1, 2},
                                              {3, 4}};
}

using namespace ::testing;


TEST(PopulationTestSuite, ShouldReturnExceptionWhenSizeOfPopulationIsZero)
{
    std::shared_ptr<PointInitializerMock> initializerMock = std::make_shared<StrictMock<PointInitializerMock>>();
    EXPECT_CALL(*initializerMock, getInitialPoints(_)).WillRepeatedly(Return(EMPTY_INITIAL_SOLUTION));

    EXPECT_THROW((Population(INVALID_PARAMETERS, initializerMock)), std::invalid_argument);
}

TEST(PopulationTestSuite, ShouldReturnNumberInPassedRange)
{
    std::shared_ptr<PointInitializerMock> initializerMock = std::make_shared<StrictMock<PointInitializerMock>>();
    EXPECT_CALL(*initializerMock, getInitialPoints(_)).WillRepeatedly(Return(INITIAL_SOLUTION));

    Population sut(PARAMETERS, initializerMock);
    auto randomNumber = sut.getRandomNumberInRange(LOWER_BOUND, UPPER_BOUND);

    EXPECT_LE(randomNumber, UPPER_BOUND);
    EXPECT_GE(randomNumber, LOWER_BOUND);
}


