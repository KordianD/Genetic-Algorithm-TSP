#pragma once

#include <string>
#include <vector>
#include <optional>
#include "GeneticAlgorithmParameters.hpp"

class Parser
{
public:
    explicit Parser(std::vector<std::string>);
    void printHelpOptions() const;
    bool isCommandPassed(std::string_view) const;
    bool isRandomModeEnabled() const;
    std::optional<GeneticAlgorithmParameters> validateInput();
    std::string getValueFromPassedCommand(std::string_view command) const;
    std::string getPassedFilePath() const;

private:
    void setSizeOfPopulationParameterFromInput();
    void setMutationRateParameterFromInput();
    void setNumberOfIterationsParameterFromInput();
    void setNumberOfPointsFromInput();

    GeneticAlgorithmParameters geneticAlgorithmParameters{};
    std::vector<std::string> arguments{};
};