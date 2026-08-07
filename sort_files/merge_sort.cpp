#include "Sort.h"


/**********************************************
	Merge Sort

	Defines merge sort function.
	Uses a wrapper so that it can be 
	passed as a function pointer.

        Program by Tressa Millering
        05/10/2026
***********************************************/

template <typename T>
void merge(std::vector<T>& vec, int i, int j, int k) {
	int mergeSize = k-i+1;
    	int mergePos = 0;
    	int left = i;
    	int right = j+1;
    	std::vector<T> merged(mergeSize);
    
    	while(left <= j && right <= k){
        	if (vec.at(left) < vec.at(right))
            		merged.at(mergePos++) = vec.at(left++);
        	else 
            		merged.at(mergePos++) = vec.at(right++);
    	}
    
    	while (right <= k)
        	merged.at(mergePos++) = vec.at(right++);
    
    	while (left <= j)
        	merged.at(mergePos++) = vec.at(left++);
        
    	for (mergePos = 0; mergePos < mergeSize; mergePos++){
        	vec.at(i+mergePos) = merged.at(mergePos);
    	}

}

template <typename T>
void next(std::vector<T>& vec, int i, int k) {  
	int j;
        if (i < k) {
        	j = (i+k)/2;

            	next<T>(vec, i, j);
            	next<T>(vec, j+1, k);
        
            	merge(vec, i, j, k);
        }
        return;
}


template <typename T>
void Sort::merge_sort(std::vector<T>& vec) {
	int i = 0;
       	int k = vec.size() - 1;
        int j;
        if (i < k) {
        	j = (i+k)/2;

            	next<T>(vec, i, j);
            	next<T>(vec, j+1, k);
        
            	merge(vec, i, j, k);
        }
        return;
}


template void Sort::merge_sort(std::vector<int>&);
template void Sort::merge_sort(std::vector<double>&);
template void Sort::merge_sort(std::vector<std::string>&);

