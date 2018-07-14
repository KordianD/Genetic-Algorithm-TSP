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

    return(0);
}