#include <iostream>
#include "Parser.hpp"
#include <algorithm>

Parser::Parser(std::vector<std::string> arguments) :
        arguments(std::move(arguments))
{}

void Parser::validateInput()
{
    if (isHelpCommandActive())
    {
        printHelpOptions();
        return;
    }


}

void Parser::printHelpOptions()
{
    std::cout << "Travelling Salesman Problem solved by Genetic Algorithm " << '\n' <<
              "Options:" << '\n' <<
              "-h | --help        Print this help" << '\n' <<
              "--sizeOfPopulation=<int>    Pass size of population" << '\n' <<
              "--mutationRate=<double>     Pass mutation rate" << '\n' <<
              "--numberOfIteration=<int>   Pass number of iterations" << '\n';

}

bool Parser::isHelpCommandActive()
{
    return std::find_if(std::begin(arguments), std::end(arguments), [](const auto &option)
    {
        return option == "--help" || option == "-h";

    }) != std::end(arguments);
}