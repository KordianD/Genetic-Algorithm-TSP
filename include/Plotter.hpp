#ifndef TSP_FINAL_PLOTTER_HPP
#define TSP_FINAL_PLOTTER_HPP

#include <vector>
#include "Point.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class Plotter
{
public:
    Plotter(int, int);
    void drawPoints(const std::vector<Point> &points) const;

private:
    cv::Mat image{};
    const int imageWidth{};
    const int imageHeight{};
};

#endif