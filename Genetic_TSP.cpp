#include "Population.hpp"
#include <algorithm>
#include <Plotter.hpp>
#include <Report.hpp>
#include <Parser.hpp>
#include <RandomPointInitializer.hpp>
#include <FilePointInitializer.hpp>

void start(std::shared_ptr<PointInitializer>, const GeneticAlgorithmParameters&, const Report &, int, int);

int main(int argc,  char* argv[])
{
    Parser parser(std::vector<std::string>(argv+1, argv + argc));
    auto parserAlgorithmParameters = parser.validateInput();

    auto imageWidth = 1700;
    auto imageHeight = 1000;

    if(not parserAlgorithmParameters)
    {
        return 0;
    }

    Report report(parser.getPassedLogFilePath(), parser.isVerboseModeEnabled());

    if (parser.isRandomModeEnabled())
    {
        start(std::make_shared<RandomPointInitializer>(imageHeight, imageWidth), *parserAlgorithmParameters, report, imageHeight, imageWidth);
    }
    else
    {
        start(std::make_shared<FilePointInitializer>(parser.getPassedFilePath()), *parserAlgorithmParameters, report, imageHeight, imageWidth);
    }

    return(0);
}

void start(std::shared_ptr<PointInitializer> pointInitializer, const GeneticAlgorithmParameters& geneticAlgorithmParameters, const Report & report, int imageHeight, int imageWidth)
{
    Population population(geneticAlgorithmParameters, std::move(pointInitializer));

    population.runAlgorithm();

    auto result = population.getBestSolutionPath();
    auto history = population.getHistoryOfLearning();
    auto fitness = population.getBestSolutionFitness();
    auto iteration = population.getNumberOfBestSolution();

    report.generateReport(history, result, fitness, iteration);

    Plotter plotter(imageHeight, imageWidth);
    plotter.drawPoints(result);
}