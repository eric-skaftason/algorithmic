cmake_minimum_required(VERSION 3.10)
project(algorithmic VERSION 0.0.1)

# REQUIRE C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp

    src/algorithms/sqrt.cpp
    src/algorithms/PerlinNoise2D.cpp
)

# define executable target
add_executable(algorithmic ${SOURCES})

# tell cmake where to get the headers
target_include_directories(algorithmic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)