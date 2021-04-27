#include <iostream>
#include <chrono>
#include "SortAlgorithms.hpp"
#include "Timer.hpp"
#include <ctime>

double FindMinimum(double* array, int size) {
	double minimum = array[0];
	for (int i = 1; i < size; ++i) {
		if (array[i] < minimum) {
			minimum = array[i];
		}
	}
	return minimum;
}

double FindMaximum(double* array, int size) {
	double maximum = array[0];
	for (int i = 1; i < size; ++i) {
		if (array[i] > maximum) {
			maximum = array[i];
		}
	}
	return maximum;
}

double FindAverage(double* array, int size) {
	double summary = 0;
	for (int i = 0; i< size; ++i) {
		summary += array[i];
	}
	return (double) summary / size;
}

bool CheckIsArraySorted(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (array[i + 1] < array[i])
            return false;
    }
    return true;
}

void CalculateQuickSortRunTime(int* static_array, int size, int count) {
	double result[count];
	int array[size];
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < size; ++j) {
			array[j] = static_array[j];
		}
	Timer timer; 
	QuickSort(array, 0, size - 1);
	timer.Stop();
	result[i] = timer.m_duration;
	}
	if (!CheckIsArraySorted(array, size)) {
		std::cout << "Something wrong in QuickSort" << std::endl;
	}

	std::cout << "__QuickSort__" << std::endl;
	std::cout << "Minimum:" << FindMinimum(result, count) << std::endl;
	std::cout << "Maximum:" << FindMaximum(result, count) << std::endl;
	std::cout << "Average:" << FindAverage(result, count) << std::endl;

}

void CalculateHeapSortRunTime(int* static_array, int size, int count) {
	double result[count];
	int array[size];
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j <size; ++j) {
			array[j] = static_array[j];
		}
	Timer timer;
	HeapSort(array, size);
	timer.Stop();
	result[i] = timer.m_duration;
	}
	if (!CheckIsArraySorted(array, size)) {
		std::cout << "Something wrong in HeapSort" << std::endl;
	}
	std::cout << "__HeapSort__" << std::endl;
	std::cout << "Minimum:" << FindMinimum(result, count) << std::endl;
	std::cout << "Maximum:" << FindMaximum(result, count) << std::endl;
	std::cout << "Average:" <<FindAverage(result, count) << std::endl;

}

void CalculateBubbleSortRunTime(int* static_array, int size, int count) {
	double result[count];
	int array[size];
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < size; ++j) {
			array[j] = static_array[j];
	}
	Timer timer;
	BubbleSort(array, size);
	timer.Stop();
	result[i] = timer.m_duration;
	}
	if (!CheckIsArraySorted(array, size)) {
		std::cout << "Something wrong in BubbleSort" <<	std::endl;
	}
	std::cout << "__BubbleSort__" << std::endl;
	std::cout << "Minimum:" << FindMinimum(result, count) << std::endl;
	std::cout << "Maximum:" << FindMaximum(result, count) << std::endl;
	std::cout << "Average:" << FindAverage(result, count) << std::endl;
}

void CalculateShellSortRunTime(int* static_array, int size, int count) {
	double result[count];
	int array[size];
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j <size; ++j) {
			array[j] = static_array[j];
	}
	Timer timer;
	ShellSort(array, size);
	timer.Stop();
	result[i] = timer.m_duration;
	}
	if (!CheckIsArraySorted(array, size)) {
		std::cout << "Something wrong in ShellSort" << std::endl;
	}
	std::cout << "__ShellSort__" << std::endl;
	std::cout << "Minimum:" << FindMinimum(result, count) << std::endl;
	std::cout << "Maximum:" << FindMaximum(result, count) << std::endl;
	std::cout << "Average:" <<FindAverage(result, count) << std::endl;	
}

void CalculateMergeSortRunTime(int* static_array, int size, int count) {
	double result[count];
	int array[size];
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j <size; ++j) {
			array[j] = static_array[j];
	}
	Timer timer;
	MergeSort(array, size); 
	timer.Stop();
	result[i] = timer.m_duration;
	}
	if (!CheckIsArraySorted(array, size)) {
		std::cout << "Something wrong in MergeSort" << std::endl;
	}
	std::cout << "__MergeSort__" << std::endl;
	std::cout << "Minimum:" << FindMinimum(result, count) << std::endl;
	std::cout << "Maximum:" << FindMaximum(result, count) << std::endl;
	std::cout << "Average:" << FindAverage(result, count) << std::endl;
}

void RunAllFunctions(int size, int count) {
	int* static_array = new int[size];
	for (int i = 0; i < size; i++) {
		static_array[i] = rand() % 50000;
	}
	CalculateQuickSortRunTime(static_array, size, count);
	std::cout << std::endl;
	CalculateHeapSortRunTime(static_array, size, count);
	std::cout << std::endl;
	CalculateBubbleSortRunTime(static_array, size, count);
	std::cout << std::endl;
	CalculateShellSortRunTime(static_array, size, count);
	std::cout << std::endl;
	CalculateMergeSortRunTime(static_array, size, count);

}

int main(int argc, char* argv[]) {
	srand(time(0));
	int size = std::stoi(argv[1]);
	int count = std::stoi(argv[2]);
	if (count >= 1 && count <= 3) {
		std::cout << "___Time is represented in milliseconds___\n\n";
		RunAllFunctions(size, count);
	} else {
		std::cout << "Wrong count!" << std::endl;
	}
    return 0;
}
