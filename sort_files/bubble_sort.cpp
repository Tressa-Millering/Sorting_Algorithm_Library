#include "Sort.h"

/**********************************************
	Bubble sort

	Defines bubble sort function

        Program by Tressa Millering
        05/10/2026
***********************************************/

template <typename T>
void Sort::bubble_sort(std::vector<T>& vec) { 
	int n = vec.size();
	int j = 0;

        for (int i = 0; i < n-1; i++) {
		bool swapped = false;
                for (j = 0; j < n-1; j++){
                        if (vec.at(j) > vec.at(j+1)){
                                T temp = vec.at(j);
                                vec.at(j) = vec.at(j+1);
                                vec.at(j+1) = temp;
                        	swapped = true;
			}
                }
		if (!swapped) break;
        }

}

template void Sort::bubble_sort(std::vector<int>&);
template void Sort::bubble_sort(std::vector<double>&);
template void Sort::bubble_sort(std::vector<std::string>&);

