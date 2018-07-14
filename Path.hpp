#pragma once
#include "Initializer.hpp"
#include <opencv2/opencv.hpp>

struct Path
{
public:
    Path(int numberOfPoints, Initializer initializer);

    std::vector<cv::Point> path;
    Initializer initializer;
};