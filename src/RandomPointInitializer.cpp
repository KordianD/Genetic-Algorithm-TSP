#include "RandomPointInitializer.hpp"

RandomPointInitializer::RandomPointInitializer(int lowerBound, int upperBound) : rand(lowerBound, upperBound)
{
    rng.seed(std::random_device()());
}

std::vector<Point> RandomPointInitializer::getInitialSolution(int sizeOfSolution)
{
	std::vector<Point> initialSolution;
	initialSolution.reserve(sizeOfSolution);

	for (auto i = 0; i < sizeOfSolution; ++i)
	{
		initialSolution.emplace_back(double(rand(rng)), double(rand(rng)));
	}

	return initialSolution;
}
