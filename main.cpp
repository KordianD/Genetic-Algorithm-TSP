#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

#include "Initializer.hpp"

struct Path
{
    Path(int numberOfPoints, Initializer initializer) : path(numberOfPoints), initializer(initializer) 
    {
        for(auto i = 0; i < numberOfPoints; ++i)
        {
             path.emplace_back(initializer.getNumber(), initializer.getNumber());
        }
    }

    std::vector<cv::Point> path;
    Initializer initializer;
};


int main()
{    
    int sizeOfImage = 800;
    int numberOfPoints = 100;
    cv::Mat image = cv::Mat::zeros(sizeOfImage, sizeOfImage, CV_8UC3);
    
    Initializer initializer(1, sizeOfImage);
    Path firstPath(numberOfPoints, initializer);    

    for(auto i = 0; i < numberOfPoints; ++i)
    {
        firstPath.path.emplace_back(initializer.getNumber(), initializer.getNumber());
    }

    // points.erase(std::unique(points.begin(), points.end()), points.end());

    // double distance = 0.0;
    // for(size_t i=0; i<points.size()-1; ++i)
    // {
    //     distance += std::sqrt(pow(points[i].x - points[i+1].x, 2) +
    //                           pow(points[i].y - points[i+1].y, 2));
    //     cv::line(image, points[i], points[i+1], cv::Scalar(0, 255, 0));
    // }
    // std::cout << distance;

    // for(auto point : points)
    //     cv::circle(image, point, 3.0, cv::Scalar(255, 255, 255), cv::FILLED, 8);

    // cv::imshow("tsp", image);
 
    // cv::waitKey(0);
    return(0);
}