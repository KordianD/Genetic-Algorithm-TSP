# Genetic-Algorithm-TSP
Travelling Salesman Problem - using genetic algorithm.


# Prerequisites
<li>OpenCV (>=3.2)
<li>matplotlib-cpp (https://github.com/lava/matplotlib-cpp)
<li>Python 2.7 with matplotlib and numpy

# Usage

After compilation run `tsp --help` for help on command line options. Available command line arguments:
```
--sizeOfPopulation=<int>    #Pass size of population
--mutationRate=<double>     #Pass mutation rate
--numberOfIteration=<int>   #Pass number of iterations
--random                    #Pass this flag to use randomly generated points
--file=pathToFile           #Pass path to file which will be used as points in algorithm
--numberOfPoints=<int>      #Pass numberOfPoints which will be used from file or randomly generated
```

Default values when not passed. You should always pass `random` or `pathToFile`. Flags `random` and `file` are mutually exclusive.
```    
numberOfPoints = 50
sizeOfPopulation = 500 
numberOfIterations = 1000
mutationRate = 0.05
```

# Example
If you want to run an algorithm with size of population = 100, number of iterations = 500 and randomly generated points.

`./tsp --sizeOfPopulation=100 --numberOfIteration=500 --random` 


# If you want to develop code and use GoogleTest and GoogleMock
1) Clone or download
2) Go to downloaded folder
3) Create directory named "lib"
4) Go to directory lib
5) Download https://github.com/google/googletest
