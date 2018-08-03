#pragma once

#include <string>
#include <vector>
#include <optional>
#include <unordered_map>
#include "GeneticAlgorithmParameters.hpp"

class Parser
{
public:
    explicit Parser(std::vector<std::string>);
    void printHelpOptions();
    bool isCommandPassed(std::string_view);
    bool isRandomModeEnabled();
    std::optional<GeneticAlgorithmParameters> validateInput();
    std::string getValueFromPassedCommand(std::string_view command);
    std::string getPassedFilePath();

private:
    void setSizeOfPopulationParameterFromInput();
    void setMutationRateParameterFromInput();
    void setNumberOfIterationsParameterFromInput();
    void setNumberOfPointsFromInput();

    GeneticAlgorithmParameters geneticAlgorithmParameters{};
    std::vector<std::string> arguments{};
};