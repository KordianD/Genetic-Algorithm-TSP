#pragma once

#include <vector>


class Chart
{
public:
    Chart(int, int);
    void drawChart(const std::vector<double> &, int, double) const;

private:
    const int imageWidth{};
    const int imageHeight{};
};