#include "Sort.h"
#include <ctime>

/**********************************************
	Quick Sort

	Defines quick sort functions. Uses
	wrapper for the same reason as merge.
	Pivot is chosen randomly. 


        Program by Tressa Millering
        05/10/2026
***********************************************/

template <typename T>
int partition(std::vector<T>& vec, int i, int k) {
	int pivot = (rand() % (k-i+1)) + i; 
	
	T temp = vec.at(pivot);
	vec.at(pivot) = vec.at(k);
	vec.at(k) = temp;

	for (int j = i--; j <= k; j++) {
		if (vec.at(j) < vec.at(k)){
			i++;
			temp = vec.at(i);
			vec.at(i) = vec.at(j);
			vec.at(j) = temp;
		}
	}

	temp = vec.at(k);
	vec.at(k) = vec.at(++i);
	vec.at(i) = temp;

	return i;
}

template <typename T>
void next(std::vector<T>& vec, int i, int k) {
	if (i >= k)
		return;
	
	int j = partition<T>(vec, i, k);

	next<T>(vec, i, j-1);
	next<T>(vec, j+1, k);
}

//To make my life easier in main.cpp, all sorts
//need the same parameters. Because of this, 
//the first quicksort partition is done in a wrapper
//of sorts. After this, next handles the rest. 
template <typename T>
void Sort::quick_sort(std::vector<T>& vec) { 
	srand(time(0)); //for partition selection

	int i = 0;
	int k = vec.size() - 1;

	if (i >= k)
		return;

	int j = partition<T>(vec, i, k);
	
	next<T>(vec, i, j-1);
	next<T>(vec, j+1, k);
}

// 0 1 2 3 4 5 6
// i k j i     k
// 0 1 2 3 4 5 6 7 8 9
// i     k j i       k


// 8 2 4 1 9 0 3 5 7 6
// i j               p

// 2 8 4 1 9 0 3 5 7 6
//   i j             p

// 2 4 8 1 9 0 3 5 7 6
//     i j           p

// 2 4 1 8 9 0 3 5 7 6
//       i j         p

// 2 4 1 8 9 0 3 5 7 6
//       i   j       p

// 2 4 1 0 9 8 3 5 7 6
//         i j       p

// 2 4 1 0 9 8 3 5 7 6
//         i   j     p

// 2 4 1 0 3 8 9 5 7 6
//           i j     p

// 2 4 1 0 3 8 9 5 7 6
//           i   j   p

// 2 4 1 0 3 5 9 8 7 6
//             i j   p

// 2 4 1 0 3 5 9 8 7 6
//             i   j p

// 2 4 1 0 3 5 6 8 7 9
//             i     js



template void Sort::quick_sort(std::vector<int>&);
template void Sort::quick_sort(std::vector<double>&);
template void Sort::quick_sort(std::vector<std::string>&);

