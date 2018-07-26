cmake_minimum_required(VERSION 3.10)
project(TSP_FINAL)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++ -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wnormalized=nfc -Wpadded -Wzero-as-null-pointer-constant -Wuseless-cast -Wwrite-strings -Wvariadic-macros -Wunused-parameter -Wunused -Wunreachable-code -Wswitch-enum -Wpointer-arith -Wpacked -Wmissing-noreturn -Wmissing-format-attribute -Wmissing-field-initializers -Wimport -Wconversion -pedantic-errors ")


find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(include)
enable_testing()

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)


file(GLOB TSP_SRC
        "src/*.cpp"
        )

file(GLOB TSP_TESTS
        "tests/*.cpp"
        )


add_executable(TSP_FINAL Genetic_TSP.cpp ${TSP_SRC})

target_link_libraries( TSP_FINAL ${OpenCV_LIBS} )

#Define your executable
add_executable(EXECUTABLE_NAME ${TSP_SRC} ${TSP_TESTS} include/Plotter.hpp)

#Link with GoogleTest
target_link_libraries(EXECUTABLE_NAME gtest gtest_main)

#Link with GoogleMock
target_link_libraries(EXECUTABLE_NAME gmock gmock_main)