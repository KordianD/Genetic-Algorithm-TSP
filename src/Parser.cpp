#include <iostream>
#include "Parser.hpp"
#include <algorithm>

Parser::Parser(std::vector<std::string> arguments) : arguments(std::move(arguments))
{}

std::string Parser::getValueFromPassedCommand(std::string_view command) const
{
    for (const auto &elem : arguments)
    {
        if (elem.find(command) != std::string::npos)
        {
            return elem.substr(elem.find('=') + 1);
        }
    }
}

std::optional<GeneticAlgorithmParameters> Parser::validateInput()
{
    if (isCommandPassed("--help"))
    {
        printHelpOptions();
        return {};
    }

    setSizeOfPopulationParameterFromInput();
    setMutationRateParameterFromInput();
    setNumberOfIterationsParameterFromInput();
    setNumberOfPointsFromInput();
    setPercentageOfChildrenFromPreviousGeneration();

    return geneticAlgorithmParameters;
}

void Parser::setSizeOfPopulationParameterFromInput()
{
    if (isCommandPassed("sizeOfPopulation"))
    {
        geneticAlgorithmParameters.sizeOfPopulation = std::stoi(getValueFromPassedCommand("sizeOfPopulation"));
    }
}


void Parser::setMutationRateParameterFromInput()
{
    if (isCommandPassed("mutationRate"))
    {
        geneticAlgorithmParameters.mutationRate = std::stod(getValueFromPassedCommand("mutationRate"));
    }
}


void Parser::setNumberOfIterationsParameterFromInput()
{
    if (isCommandPassed("numberOfIterations"))
    {
        geneticAlgorithmParameters.numberOfIterations = std::stoi(getValueFromPassedCommand("numberOfIterations"));
    }

}

void Parser::setNumberOfPointsFromInput()
{
    if (isCommandPassed("numberOfPoints"))
    {
        geneticAlgorithmParameters.numberOfPoints = std::stoi(getValueFromPassedCommand("numberOfPoints"));
    }
}

void Parser::setPercentageOfChildrenFromPreviousGeneration()
{
    if (isCommandPassed("percentageOfChildrenFromPreviousGeneration"))
    {
        geneticAlgorithmParameters.percentageOfChildrenFromPreviousGeneration = std::stod(
                getValueFromPassedCommand("percentageOfChildrenFromPreviousGeneration"));
    }
}

bool Parser::isRandomModeEnabled() const
{
    return isCommandPassed("random");
}

bool Parser::isVerboseModeEnabled() const
{
    return isCommandPassed("verbose");
}

bool Parser::isCommandPassed(std::string_view command) const
{
    return std::any_of(std::begin(arguments), std::end(arguments), [command](const auto &elem)
    { return elem.find(command) != std::string::npos; });
}

std::string Parser::getPassedFilePath() const
{
    return getValueFromPassedCommand("file");
}

std::optional<std::string> Parser::getPassedLogFilePath() const
{
    if (isCommandPassed("log"))
    {
        return getValueFromPassedCommand("log");
    }
    else
    {
        return {};
    }
}

void Parser::printHelpOptions() const
{
    std::cout << "Travelling Salesman Problem solved by Genetic Algorithm " << '\n' <<
              "Options:" << '\n' <<
              "--help           Print this help" << '\n' <<
              "--sizeOfPopulation=<int>    Pass size of population" << '\n' <<
              "--mutationRate=<double>     Pass mutation rate" << '\n' <<
              "--numberOfIteration=<int>   Pass number of iterations" << '\n' <<
              "--random   Pass this flag to use randomly generated points" << '\n' <<
              "--file=pathToFile  Pass path to file which will be used as points in algorithm" << '\n' <<
              "--log=pathToFile  Pass path to file which will be used as final report" << '\n' <<
              "--numberOfPoints=<int> Pass numberOfPoints which will be used from file or randomly generated" << '\n' <<
              "--verbose Pass this flag to write report to standard output" << '\n' <<
              "--percentageOfChildrenFromPreviousGeneration=<double> Pass which percentage best from previous generation will be included" << '\n';
}
