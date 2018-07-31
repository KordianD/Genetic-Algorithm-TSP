#pragma once

#include <string>
#include <vector>
#include <optional>
#include "GeneticAlgorithmParameters.hpp"

class Parser
{
public:
    Parser(std::vector<std::string>);
    void printHelpOptions();
    bool isHelpCommandActive();
    std::optional<GeneticAlgorithmParameters> validateInput();

private:
    std::vector<std::string> arguments{};
};