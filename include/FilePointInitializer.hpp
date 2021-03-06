#ifndef TSP_FINAL_FILEPOINTINITIALIZER_HPP
#define TSP_FINAL_FILEPOINTINITIALIZER_HPP

#include "PointInitializer.hpp"
#include <string>
#include <fstream>

class FilePointInitializer : public PointInitializer
{
public:
    FilePointInitializer(const std::string &);

    std::vector<Point> getInitialPoints(int) override;

private:
    std::ifstream infile{};
};

#endif
