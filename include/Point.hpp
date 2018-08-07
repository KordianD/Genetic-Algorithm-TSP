#ifndef TSP_FINAL_POINT_HPP
#define TSP_FINAL_POINT_HPP

struct Point
{
    Point() = default;

    Point(double x, double y) : x(x), y(y)
    {}

    bool operator==(const Point &rhs) const
    {
        return rhs.x == x and rhs.y == y;
    }

    double x = 0;
    double y = 0;
};

#endif
