#include <vector>
#include "Initializer.hpp"
#include "Path.hpp"

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
    return(0);
}