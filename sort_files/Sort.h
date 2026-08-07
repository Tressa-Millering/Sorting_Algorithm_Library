#ifndef SORT_H
#define SORT_H

/**********************************************
	Sort.h

	Provides the interface to main.cpp
	for sorting functions

        Program by Tressa Millering
        05/10/2026
***********************************************/


#include <vector>
#include <string>

class Sort {

public:
	template <typename T>
	static void quick_sort(std::vector<T>& v);

	template <typename T>
	static void merge_sort(std::vector<T>& v);

	template <typename T>
	static void bubble_sort(std::vector<T>& v);

	template <typename T>
	static void insertion_sort(std::vector<T>& v);

	template <typename T>
	static void selection_sort(std::vector<T>& v);

};

#endif
