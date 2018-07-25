#include "FilePointInitializer.hpp"
#include <iostream>


FilePointInitializer::FilePointInitializer(const std::string& file) : infile(file){}

std::vector<Point> FilePointInitializer::getInitialPoints(int sizeOfInitialSolution)
{
    double x, y;
    std::vector<Point> initialSolution;
    initialSolution.reserve(sizeOfInitialSolution);

    while (infile >> x >> y)
    {
        initialSolution.emplace_back(x, y);
        if (initialSolution.size() == sizeOfInitialSolution)
        {
            break;
        }
    }

    if (initialSolution.size() != sizeOfInitialSolution)
    {
        throw std::invalid_argument("There are not enough data to load from file");
    }

    infile.clear();
    infile.seekg(0, std::ios::beg);
    return initialSolution;
}