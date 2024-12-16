cmake_minimum_required(VERSION 3.29)
project(fitness C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_subdirectory(src)
add_subdirectory(test)
enable_testing(test.c)


