#pragma once

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
