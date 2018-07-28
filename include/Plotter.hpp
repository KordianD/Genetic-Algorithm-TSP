#pragma once

#include <vector>
#include "Point.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class Plotter
{
public:
    Plotter(int, int);
    void drawPoints(const std::vector<Point> &points);

private:
    cv::Mat image{cv::Mat::zeros(400, 400, CV_8UC3)};
    const int imageWidth{};
    const int imageHeight{};
};