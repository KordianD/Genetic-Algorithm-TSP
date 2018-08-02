#pragma once

#include <string>
#include <vector>
#include <optional>
#include <unordered_map>
#include "GeneticAlgorithmParameters.hpp"

class Parser
{
public:
    Parser(std::vector<std::string>);
    void printHelpOptions();
    bool isCommandPassed(std::string_view);
    std::optional<GeneticAlgorithmParameters> validateInput();
    double getValueFromPassedCommand(std::string_view command);

private:
    void setSizeOfPopulationParameterFromInput();
    void setMutationRateParameterFromInput();
    void setNumberOfIterationsParameterFromInput();

    GeneticAlgorithmParameters geneticAlgorithmParameters{};
    std::vector<std::string> arguments{};
};