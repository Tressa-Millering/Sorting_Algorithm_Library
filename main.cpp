/**********************************************
	Sorting Program

	This program sorts a file with
	5 different sorts, measures the time
	it takes, and outputs the results.

        Program by Tressa Millering
        05/10/2026
***********************************************/

#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include "sort_files/Sort.h"

#include <windows.h>

#if DEBUG
template <typename T>
void printVector(const std::vector<T>& source){
	for (T t : source) std::cout << std::setprecision(15) << t << std::endl;
}
#endif



template <typename Func, typename T>
auto run_experiment(Func fn, const std::vector<T>& source, char* fileName, std::string sortName) {
	std::vector<T> vec(source);
	auto t0 = std::chrono::high_resolution_clock::now();
	fn(vec);
	auto t1 = std::chrono::high_resolution_clock::now();

#if DEBUG
	std::cout << "\n\nSORTED VECTOR\n";
	printVector(vec);
#endif
	std::string outputName = std::string(fileName);
	size_t pos = outputName.find_last_of("/");

	outputName.erase(0, pos+1);
	outputName.insert(0, sortName + "_sorted_");

	std::ofstream outputFile;
	outputFile.open(outputName);
	if (outputFile.is_open()){
		for (T i : vec)
			outputFile << i << "\n";

		std::cout << "Results written to file: "<< outputName << "\n";
	}

	bool sorted = true;
	for (int i = 0; i < vec.size()-1; i++){
		if (vec.at(i) > vec.at(i+1)){
			sorted = false;
			break;
		}
	}
	std::cout << "Sorted properly (ascending)? --> " << (sorted ? "Yes":"No") << "\n\n";


        return std::chrono::duration_cast<std::chrono::milliseconds>( t1 - t0).count();
}



int typeCheck(const char* in) {
	if (!in || *in == '\0') return 0;

	char* end;

	if (strchr(in, '.')){
		strtod(in, &end);
		if (*end == '\0')
			return 2;
		return 0;
	}

	strtol(in, &end, 10);
	if (*end == '\0') return 1;

	return 0;
}



template <typename T>
void sortFile(std::ifstream& file, char* fileName) {
	int currSize = 1000;
	int i = -1;
	std::vector<T> source(1000);
	std::string line;
	while (getline(file, line)){
		i++;
		if (i == currSize-1){
			currSize += 1000;
			source.resize(currSize);
		}
		std::istringstream iss(line);
		T val;
		iss >> val;
		source.at(i) = val;

	}

	source.resize(i+1);

#if DEBUG
	std::cout << "UNSORTED ORIGINAL:\n";
	printVector(source);
#endif

	auto selDur = run_experiment(Sort::selection_sort<T>, source, fileName, "sel");
	auto insDur = run_experiment(Sort::insertion_sort<T>, source, fileName, "ins");
	auto bubDur = run_experiment(Sort::bubble_sort<T>, source, fileName, "bubble");
	auto mergeDur = run_experiment(Sort::merge_sort<T>, source, fileName, "merge");
	auto quickDur = run_experiment(Sort::quick_sort<T>, source, fileName, "quick");

	std::cout << "╔════════════════╤════════════════╗\n";
	std::cout << "║ Sort Function  │ Sort Time (ms) ║\n";
	std::cout << "╠════════════════╪════════════════╣\n";
	std::cout << "║ Selection Sort ┆ "<< std::setw(14) << selDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Insertion Sort ┆ "<< std::setw(14) << insDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Bubble Sort    ┆ "<< std::setw(14) << bubDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Merge Sort     ┆ "<< std::setw(14) << mergeDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Quick Sort     ┆ "<< std::setw(14) << quickDur << " ║\n";
	std::cout << "╚════════════════╧════════════════╝\n";

}



//There is a string specific version because
//the process of loading the data into the vector
//is different for strings and numerics due to whitespace.
template<>
void sortFile<std::string>(std::ifstream& file, char* fileName) {
        int currSize = 1000;
        int i = -1;
        std::vector<std::string> source(1000);
        std::string line;
        while (getline(file, line)){
                i++;
                if (i == currSize-1){
                        currSize += 1000;
                        source.resize(currSize);
                }
                std::istringstream iss(line);
                std::string val, next;
                iss >> val;
                while (iss >> next) val += " " + next;
                source.at(i) = val;
        }

        source.resize(i+1);

#if DEBUG
	printVector(source);
#endif

	auto selDur = run_experiment(Sort::selection_sort<std::string>, source, fileName, "sel");
	auto insDur = run_experiment(Sort::insertion_sort<std::string>, source, fileName, "ins");
	auto bubDur = run_experiment(Sort::bubble_sort<std::string>, source, fileName, "bubble");
	auto mergeDur = run_experiment(Sort::merge_sort<std::string>, source, fileName, "merge");
	auto quickDur = run_experiment(Sort::quick_sort<std::string>, source, fileName, "quick");

	std::cout << "╔════════════════╤════════════════╗\n";
	std::cout << "║ Sort Function  │ Sort Time (ms) ║\n";
	std::cout << "╠════════════════╪════════════════╣\n";
	std::cout << "║ Selection Sort ┆ "<< std::setw(14) << selDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Insertion Sort ┆ "<< std::setw(14) << insDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Bubble Sort    ┆ "<< std::setw(14) << bubDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Merge Sort     ┆ "<< std::setw(14) << mergeDur << " ║\n";
	std::cout << "╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n";
	std::cout << "║ Quick Sort     ┆ "<< std::setw(14) << quickDur << " ║\n";
	std::cout << "╚════════════════╧════════════════╝\n";

}





int main(int argc, char* argv[]) {
	SetConsoleOutputCP(CP_UTF8);
#if DEBUG
	std::cout << "\n\n**************\nMAIN START\n**************\n\n";
#endif

	std::ifstream file;
	file.open(argv[1]);

	if (!file.is_open()){
		std::cerr << "Could not open file." << std::endl;
		return -1;
	}

	std::string input;
	getline(file, input);

	int type = typeCheck(input.c_str());

	file.seekg(0);

#if DEBUG
	switch (type){
		case 0: std::cout << "STRING" << std::endl; break;
		case 1: std::cout << "INT" << std::endl; break;
		case 2: std::cout << "DOUBLE" << std::endl; break;
	}

#endif
	std::cout << "\nSORTING DATAFILE: " << argv[1] << "\n";

	switch(type){
		case 0: sortFile<std::string>(file, argv[1]); break;
		case 1: sortFile<int>(file, argv[1]); break;
		case 2: sortFile<double>(file, argv[1]); break;
	}

	std::cout << "\n";
#if DEBUG
	std::cout << "\n\n**************\nMAIN END\n**************\n\n";
#endif

	return 0;
}
