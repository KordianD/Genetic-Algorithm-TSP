#include <gtest/gtest.h>
#include "Population.hpp"
#include "PointInitializerMock.hpp"


namespace
{
    constexpr int NUMBER_OF_POINTS{100};
    constexpr int ZERO_SIZE_OF_POPULATION{0};
    constexpr int NUMBER_OF_INTERATIONS{1000};
    constexpr double MUTATION_RATE{0.05};
    constexpr double PERCENTAGE_OF_CHILDREN_FROM_PREVIOUS_GENERATION{0.9};
    constexpr GeneticAlgorithmParameters INVALID_PARAMETERS{NUMBER_OF_POINTS, ZERO_SIZE_OF_POPULATION,
                                                            NUMBER_OF_INTERATIONS, MUTATION_RATE,
                                                            PERCENTAGE_OF_CHILDREN_FROM_PREVIOUS_GENERATION};
    constexpr int LOWER_BOUND{20};
    constexpr int UPPER_BOUND{77};
    const std::vector<Point> EMPTY_INITIAL_SOLUTION{};

}

using namespace ::testing;


TEST(PopulationTestSuite, ShouldReturnExceptionWhenSizeOfPopulationIsZero)
{
    std::shared_ptr<PointInitializerMock> initializerMock = std::make_shared<StrictMock<PointInitializerMock>>();
    EXPECT_CALL(*initializerMock, getInitialPoints(_)).WillRepeatedly(Return(EMPTY_INITIAL_SOLUTION));

    EXPECT_THROW((Population(INVALID_PARAMETERS, initializerMock)), std::invalid_argument);
}

