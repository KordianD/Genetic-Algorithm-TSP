#include <gtest/gtest.h>
#include "Parser.hpp"

namespace
{
    const std::vector<std::string> ARGUMENTS_WITH_HELP {"--RANDOM", "ran", "--help"};
}

using namespace ::testing;


TEST(PathTestSuite, ShouldReturnTrueWhenHelpFlagWasPassed)
{
    Parser sut(ARGUMENTS_WITH_HELP);

    EXPECT_TRUE(sut.isHelpCommandActive());
}





