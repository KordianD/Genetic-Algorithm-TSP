cmake_minimum_required(VERSION 3.10)
project(TSP_FINAL)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Weffc++ -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wnormalized=nfc -Wpadded -Wzero-as-null-pointer-constant -Wuseless-cast -Wwrite-strings -Wvariadic-macros -Wunused-parameter -Wunused -Wunreachable-code -Wswitch-enum -Wpointer-arith -Wpacked -Wmissing-noreturn -Wmissing-format-attribute -Wmissing-field-initializers -Wimport -Wconversion -pedantic-errors ")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

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

add_executable(tsp Genetic_TSP.cpp ${TSP_SRC})

set_target_properties(tsp
        PROPERTIES COMPILE_FLAGS ${GCC_COVERAGE_COMPILE_FLAGS})

target_link_libraries(tsp ${OpenCV_LIBS} )

add_executable(unit_tests_exe ${TSP_SRC} ${TSP_TESTS})

target_link_libraries(unit_tests_exe gtest gtest_main)

target_link_libraries(unit_tests_exe gmock gmock_main)

target_link_libraries(unit_tests_exe ${OpenCV_LIBS} )