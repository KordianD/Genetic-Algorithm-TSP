#include <string>
#include <numeric>
#include "Chart.hpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

Chart::Chart(int imageHeight, int imageWidth) : imageHeight(imageHeight), imageWidth(imageWidth) {}

void Chart::drawChart(const std::vector<double> & history, int iteration, double fitness) const
{
    //plt::figure_size(imageHeight, imageWidth);
    plt::plot(history, "bo");
    plt::plot({double(iteration)}, {fitness}, "ro");

    plt::xlabel("iteration");
    plt::ylabel("fitness");
    std::vector<std::string> title {"Best result = ", std::to_string(fitness), " at iteration: ", std::to_string(iteration)};
    std::string accuTitle;
    accuTitle = accumulate(begin(title), end(title), accuTitle);
    plt::title(accuTitle);
    plt::show();
}
