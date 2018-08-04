#include "Plotter.hpp"

Plotter::Plotter(int imageHeight, int imageWidth) : imageHeight(imageHeight), imageWidth(imageWidth)
{
    image = cv::Mat::zeros(imageHeight, imageWidth, CV_8UC3);
}

void Plotter::drawPoints(const std::vector<Point> &points) const
{
    for (size_t i = 0; i < points.size() - 1; ++i)
    {
        cv::line(image, cv::Point(points[i].x, points[i].y), cv::Point(points[i + 1].x, points[i + 1].y),
                 cv::Scalar(0, 255, 0));
    }

    for (const auto &point : points)
    {
        cv::circle(image, cv::Point(point.x, point.y), 3.0, cv::Scalar(255, 255, 255), cv::FILLED, 8);
    }

    cv::imshow("TSP", image);
    cv::waitKey(0);
}