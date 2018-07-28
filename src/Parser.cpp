#include <iostream>
#include "Parser.hpp"

Parser::Parser(std::vector<std::string> && arguments) : arguments(std::move(arguments))
{
    for (auto elem : arguments)
    {
        std::cout << elem << " ";
    }
}