cmake_minimum_required(VERSION 3.25)
project(cxx_by_example)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(test)
