#include "RandomPointInitializer.hpp"

RandomPointInitializer::RandomPointInitializer(int imageHeight, int imageWidth) : randX(0, imageWidth),
                                                                                  randY(0, imageHeight)
{
    rng.seed(std::random_device()());
}

std::vector<Point> RandomPointInitializer::getInitialPoints(int sizeOfSolution)
{
    std::vector<Point> initialSolution;
    initialSolution.reserve(sizeOfSolution);

    for (auto i = 0; i < sizeOfSolution; ++i)
    {
        initialSolution.emplace_back(double(randX(rng)), double(randY(rng)));
    }

    return initialSolution;
}
