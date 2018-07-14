#pragma once

#include "Initializer.hpp"
#include <opencv2/opencv.hpp>

struct Path
{
public:
    Path(int, Initializer);
    auto calculateFitness();

    std::vector<cv::Point> path;
    Initializer initializer;
    int numberOfPoints;
};