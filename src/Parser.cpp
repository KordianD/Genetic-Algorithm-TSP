#include <iostream>
#include "Parser.hpp"
#include <algorithm>

Parser::Parser(std::vector<std::string> arguments) : arguments(std::move(arguments)) {}

double Parser::getValueFromPassedCommand(std::string_view command)
{
    for (const auto & elem : arguments)
    {
        if (elem.find(command) != std::string::npos)
        {
            return std::stod(elem.substr(elem.find('=') + 1));
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

    return geneticAlgorithmParameters;
}

void Parser::setSizeOfPopulationParameterFromInput()
{
    if (isCommandPassed("sizeOfPopulation"))
    {
        geneticAlgorithmParameters.sizeOfPopulation = int (getValueFromPassedCommand("sizeOfPopulation"));
    }
}


void Parser::setMutationRateParameterFromInput()
{
    if (isCommandPassed("mutationRate"))
    {
        geneticAlgorithmParameters.mutationRate = getValueFromPassedCommand("mutationRate");
    }
}


void Parser::setNumberOfIterationsParameterFromInput()
{
    if (isCommandPassed("numberOfIterations"))
    {
        geneticAlgorithmParameters.numberOfIterations = int (getValueFromPassedCommand("numberOfIterations"));
    }

}

bool Parser::isCommandPassed(std::string_view command)
{
    return std::find_if(std::begin(arguments), std::end(arguments), [command](const auto &option)
    {
        return option == command;

    }) != std::end(arguments);
}

void Parser::printHelpOptions()
{
    std::cout << "Travelling Salesman Problem solved by Genetic Algorithm " << '\n' <<
              "Options:" << '\n' <<
              "--help           Print this help" << '\n' <<
              "--sizeOfPopulation=<int>    Pass size of population" << '\n' <<
              "--mutationRate=<double>     Pass mutation rate" << '\n' <<
              "--numberOfIteration=<int>   Pass number of iterations" << '\n';

}
