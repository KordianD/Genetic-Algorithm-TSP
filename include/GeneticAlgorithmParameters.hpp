#ifndef TSP_FINAL_GENETICALGORITHMPARAMETERS_HPP
#define TSP_FINAL_GENETICALGORITHMPARAMETERS_HPP

#include <string>
struct GeneticAlgorithmParameters
{
    int numberOfPoints{50};
    int sizeOfPopulation{500};
    int numberOfIterations{1000};
    double mutationRate{0.05};
};

#endif
