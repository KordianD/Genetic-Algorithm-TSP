cmake_minimum_required(VERSION 3.10)
project(TSP_FINAL)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
enable_testing()

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)


file(GLOB TSP_SRC
        "src/*.cpp"
        )

add_executable(TSP_FINAL Genetic_TSP.cpp ${TSP_SRC})

#Define your executable
add_executable(EXECUTABLE_NAME ${TSP_SRC} tests/UnitTests.cpp tests/PathTestSuite.cpp tests/PointTestSuite.cpp tests/PopulationTestSuite.cpp
        tests/RandomPointInitializerTestSuite.cpp)

#Link with GoogleTest
target_link_libraries(EXECUTABLE_NAME gtest gtest_main)

#Link with GoogleMock
target_link_libraries(EXECUTABLE_NAME gmock gmock_main)