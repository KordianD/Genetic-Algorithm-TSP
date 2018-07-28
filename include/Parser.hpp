#pragma once

#include <string>
#include <vector>

class Parser
{
public:
    Parser(std::vector<std::string>&&);

private:
    std::vector<std::string> arguments {};
};