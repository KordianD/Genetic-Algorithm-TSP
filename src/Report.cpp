
#include "Report.hpp"
#include <fstream>
#include <iostream>

Report::Report(const std::optional<std::string> & path, bool verbose): pathToFile(path), isVerbose(verbose) {}

void Report::generateReport(const std::vector<double> &history, const std::vector<Point> &result, double fitness,
                            int iteration) const
{
    if(pathToFile.has_value())
    {
        std::ofstream outputFile{};
        outputFile.open(*pathToFile);
        if(outputFile.is_open())
        {
            saveOrPrintFile(outputFile, history, result, fitness, iteration);
            outputFile.close();
        }
    }
    if(isVerbose)
    {
        saveOrPrintFile(std::cout, history, result, fitness, iteration);
    }
}

void Report::saveOrPrintFile(std::ostream& output, const std::vector<double> & history, const std::vector<Point> & result, double fitness,  int iteration) const
{
    output<<"Report \n"
            "Best result = " << fitness << " at " << iteration << " iteration\n"
            "Best solution points position: \n"
            "x   y\n";
    for (const auto &point : result)
    {
        output<<point.x<<" "<<point.y<<"\n";
    }
    output<<"History of learning:\n"
            "iteration: score\n";
    auto i = 0;
    for (const auto &solution : history)
    {
        output<<i<<": "<<solution<<"\n";
        i++;
    }
}

