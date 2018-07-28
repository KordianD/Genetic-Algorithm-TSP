#pragma once


struct GeneticAlgorithmParameters
{
    int numberOfPoints{50};
    int sizeOfPopulation{500};
    int numberOfIterations{1000};
    double mutationRate{0.05};
};
