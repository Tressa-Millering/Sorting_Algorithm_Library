# Sorting Algorithm Library
This is a library of the major sorting algorithms, all hand coded as an exercise in my C++ course.
Also included is a program for evaluating the efficiency of each algorithm comparatively.

The testing program (`main.cpp`) takes a text file as input and reads it into memory as a vector. It then applies the five implemented sorts on the vector, being 
selection sort, insertion sort, bubble sort, merge sort, and quick sort.  
The results of the algorithm are written to a new file, and this file is then verified 
to be sorted in ascending order.  
Finally, a table is output showing the time in milliseconds that each sort took.

## Build Options
The `sort_files` directory contains a header file defining the Sort class, and then a separate `.cpp` file for each sort. 
This structure allows for new sorts to be added to the library quite easily.  
Two build options are available, being CMake or Makefile, with the Makefile providing a few more build options and 
tools for making testing easier. 

## Data Files
This repository contains three files of randomly generated data of three different data types, being integer, double, and string. 
They are each around 20,000 lines long. 
