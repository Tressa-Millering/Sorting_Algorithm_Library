#include "Sort.h"

/**********************************************
	Selection sort

	Defines selection sort function

        Program by Tressa Millering
        05/10/2026
***********************************************/


template <typename T>
void Sort::selection_sort(std::vector<T>& vec) { 
	int n = vec.size();
	int j = 0;

	for (int i = 0; i < n; i++) {
                int min = i;
                for (j = i+1; j < n; j++){
                        //find the smallest element in the range given by j
                        if (vec.at(j) < vec.at(min))
                                min = j;
                }
                //swap (selected element with ith element
		if (i != min) {
                	T temp = vec.at(i);
                	vec.at(i) = vec.at(min);
                	vec.at(min) = temp;
		}
        }
}

template void Sort::selection_sort(std::vector<int>&);
template void Sort::selection_sort(std::vector<double>&);
template void Sort::selection_sort(std::vector<std::string>&);
