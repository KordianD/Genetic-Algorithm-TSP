#include <gtest/gtest.h>
#include "Parser.hpp"

namespace
{
    const std::vector<std::string> ARGUMENTS_WITH_HELP{"--help"};
    const std::vector<std::string> ARGUMENTS_WITHOUT_HELP{"--RANDOM", "ran", "help"};
}

using namespace ::testing;


TEST(ParserTestSuite, ShouldReturnTrueWhenHelpFlagWasPassed)
{
    Parser sut(ARGUMENTS_WITH_HELP);

    EXPECT_TRUE(sut.isCommandPassed("--help"));
}

TEST(ParserTestSuite, ShouldReturnFalseWhenHelpFlagWasNotPassed)
{
    Parser sut(ARGUMENTS_WITHOUT_HELP);

    EXPECT_FALSE(sut.isCommandPassed("--help"));
}

TEST(ParserTestSUite, ShouldReturnEmptyOptionalWhenHelpFlagWasPassed)
{
    Parser sut(ARGUMENTS_WITH_HELP);
    auto validatedValue = sut.validateInput();
    
    EXPECT_FALSE(validatedValue.has_value());
}




