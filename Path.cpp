#include "Path.hpp"

Path::Path(int numberOfPoints, Initializer initializer) : path(numberOfPoints), initializer(initializer)
{
    for(auto i = 0; i < numberOfPoints; ++i)
    {
        path.emplace_back(initializer.getNumber(), initializer.getNumber());
    }
}
