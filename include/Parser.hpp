#pragma once

#include <string>
#include <vector>

class Parser
{
public:
    Parser(const std::string &, std::vector<std::string>);
    void printHelpOptions();
    bool isHelpCommandActive();
    void validateInput();

private:
    std::vector<std::string> arguments{};
    std::string programName;
};