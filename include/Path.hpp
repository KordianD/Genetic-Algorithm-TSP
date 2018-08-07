#ifndef TSP_FINAL_PATH_HPP
#define TSP_FINAL_PATH_HPP

#include "Point.hpp"
#include "PointInitializer.hpp"
#include <vector>
#include <memory>

class Path
{
public:
    explicit Path(std::vector<Point>);
    double getFitness() const;
    double calculateFitness() const;
    std::vector<Point> getPath() const;
    void mutate(int, int);
    std::vector<Point> crossover(const Path &parent) const;

private:
    std::vector<Point> path;
    double fitness{};
};

#endif
