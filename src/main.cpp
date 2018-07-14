#include <vector>
#include "Initializer.hpp"
#include "Population.hpp"

int main()
{ 
    int sizeOfImage = 800;
    int numberOfPoints = 100;
    int sizeOfPopulation = 100;
    cv::Mat image = cv::Mat::zeros(sizeOfImage, sizeOfImage, CV_8UC3);
    
    Initializer initializer(1, sizeOfImage);
    
    Population population(sizeOfPopulation, numberOfPoints, initializer);   

    return(0);
}