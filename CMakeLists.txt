cmake_minimum_required(VERSION 4.0)
project(SortingLibrary)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortSpeedTest main.cpp
        sort_files/bubble_sort.cpp
        sort_files/insertion_sort.cpp
        sort_files/merge_sort.cpp
        sort_files/quick_sort.cpp
        sort_files/selection_sort.cpp)
