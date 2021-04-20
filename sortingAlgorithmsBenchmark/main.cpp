#include <iostream>

#include "Sortings.hpp"
#include "Benchmark.hpp"

using namespace Sortings;

void TestsCall(int argc, char* argv[])
{
	if (3 != argc) {
		std::cerr << "Error: Please, enter the size of array and tests count." << std::endl;
		return;
	}
	
	if (3 < atoi(argv[2]) || atoi(argv[2]) < 1) {
		std::cerr << "Warning: The count of tests should be less than 4." << std::endl;
		return;
	}

	int size = atoi(argv[1]);
	int tests_count = atoi(argv[2]);	
	int* array = RandomArrayGenerator(size);

	std::cout << std::endl << "Runing time of the BubbleSort:    ";
	Testing1(array, size, BubbleSort, tests_count);
	
	std::cout << std::endl << "Runing time of the SelectionSort: ";
	Testing1(array, size, SelectionSort, tests_count);
	
	std::cout << std::endl << "Runing time of the InsertionSort: ";
	Testing1(array, size, InsertionSort, tests_count);
	
	std::cout << std::endl << "Runing time of the HeapSort:      ";
	Testing1(array, size, HeapSort, tests_count);
	
	std::cout << std::endl << "Runing time of the ShellSort:     ";
	Testing1(array, size, ShellSort, tests_count);
	
	std::cout << std::endl << "Runing time of the QuickSort:     ";
	Testing2(array, 0, size - 1, QuickSort, tests_count);
	
	std::cout << std::endl << "Runing time of the MergeSort:     ";
	Testing2(array, 0, size - 1, MergeSort, tests_count);	
}

int main(int argc, char* argv[])
{
	TestsCall(argc, argv);
	
	return 0;
}
