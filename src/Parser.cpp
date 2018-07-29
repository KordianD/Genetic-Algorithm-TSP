#include <iostream>
#include "Parser.hpp"
#include <algorithm>

Parser::Parser(std::vector<std::string> arguments) :
        arguments(std::move(arguments))
{}

std::optional<GeneticAlgorithmParameters> Parser::validateInput()
{
    if (isHelpCommandActive())
    {
        printHelpOptions();
        return {};
    }
    return GeneticAlgorithmParameters{50, 500, 1000, 0.05};
}

void Parser::printHelpOptions()
{
    std::cout << "Travelling Salesman Problem solved by Genetic Algorithm " << std::endl <<
              "Options:" << std::endl <<
              "-h | --help        Print this help" << std::endl <<
              "--sizeOfPopulation=<int>    Pass size of population" << std::endl <<
              "--mutationRate=<double>     Pass mutation rate" << std::endl <<
              "--numberOfIteration=<int>   Pass number of iterations" << std::endl;

}

bool Parser::isHelpCommandActive()
{
    return std::find_if(std::begin(arguments), std::end(arguments), [](const auto &option)
    {
        return option == "--help" || option == "-h";

    }) != std::end(arguments);
}