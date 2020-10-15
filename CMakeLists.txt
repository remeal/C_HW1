cmake_minimum_required(VERSION 3.1)

project(testy)

set(CMAKE_C_FLAGS "-ftest-coverage")

set(CMAKE_C_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/testy/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(testy ${sources})