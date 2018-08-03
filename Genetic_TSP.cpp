#include "Population.hpp"
#include <algorithm>
#include <Plotter.hpp>
#include <Parser.hpp>
#include <RandomPointInitializer.hpp>
#include <FilePointInitializer.hpp>
#include "GeneticAlgorithmParameters.hpp"

void start(std::shared_ptr<PointInitializer>, const GeneticAlgorithmParameters&, int, int);

int main(int argc,  char* argv[])
{

    Parser parser(std::vector<std::string>(argv+1, argv + argc));
    auto parserAlgorithmParameters = parser.validateInput();

    auto imageWidth = 1700;
    auto imageHeight = 1000;

    if(not parserAlgorithmParameters.has_value())
    {
        return(0);
    }

    if (parser.isRandomModeEnabled())
    {
        start(std::make_shared<RandomPointInitializer>(imageHeight, imageWidth), *parserAlgorithmParameters, imageHeight, imageWidth);
    }
    else
    {
        start(std::make_shared<FilePointInitializer>(parser.getPassedFilePath()), *parserAlgorithmParameters, imageHeight, imageWidth);
    }

    return(0);
}

void start(std::shared_ptr<PointInitializer> pointInitializer, const GeneticAlgorithmParameters& geneticAlgorithmParameters, int imageHeight, int imageWidth)
{
    Population population(geneticAlgorithmParameters, pointInitializer);

    population.runAlgorithm();

    auto result = population.getBestSolutionPath();

    Plotter plotter(imageHeight, imageWidth);
    plotter.drawPoints(result);
}