
#include "Sort.h"

/**********************************************
	Insertion Sort

	Defines insertion sort function	

        Program by Tressa Millering
        05/10/2026
***********************************************/



template <typename T>
void Sort::insertion_sort(std::vector<T>& vec) { 
	int n = vec.size();
	int j = 0;

	for (int i = 0; i < n; i++) {
		for (j = i; j > 0; j--){
			if (vec.at(j) < vec.at(j-1)){
				T temp = vec.at(j);
				vec.at(j) = vec.at(j-1);
				vec.at(j-1) = temp;
			} else break;
		}
	}
}

template void Sort::insertion_sort(std::vector<int>&);
template void Sort::insertion_sort(std::vector<double>&);
template void Sort::insertion_sort(std::vector<std::string>&);

