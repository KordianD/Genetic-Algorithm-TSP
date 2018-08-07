#ifndef TSP_FINAL_POINTINITIALIZER_HPP
#define TSP_FINAL_POINTINITIALIZER_HPP

#include <Path.hpp>

class PointInitializer
{
public:
    virtual ~PointInitializer() = default;
    virtual std::vector<Point> getInitialPoints(int) = 0;

};


#endif
