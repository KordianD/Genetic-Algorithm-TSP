#include <iostream>
#include "Parser.hpp"
#include <algorithm>

Parser::Parser(const std::string &programName, std::vector<std::string> arguments) : programName(programName),
                                                                                     arguments(std::move(arguments))
{}

void Parser::validateInput()
{}

void Parser::printHelpOptions()
{
    std::cout << programName << "[options]" << std::endl <<
              "Options:" << std::endl <<
              "-h | --help        Print this help" << std::endl <<
              "-v | --version     Print the SVN version" << std::endl <<
              "-V | --Version     Print the proxy version" << std::endl <<
              "-d | --daemonize   Run as daemon" << std::endl <<
              "-P | --pidfile     Path to PID file (default: " << std::endl;
}

bool Parser::isHelpCommandActive()
{
    return std::find_if(std::begin(arguments), std::end(arguments), [](const auto &option)
    {
        return option == "--help" || option == "-h";

    }) != std::end(arguments);
}