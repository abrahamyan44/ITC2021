#include <iostream>

#include "Sortings.hpp"
	
void Testing1(int* array, int size, void (*function_name)(int*, int))
{
	std::cout << "Before Sorting: ";

	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;

	if (function_name == Sortings::BubbleSort) {	
		Sortings::BubbleSort(array, size);
	} else if (function_name == Sortings::InsertionSort) {	
		Sortings::InsertionSort(array, size);
	} else if (function_name == Sortings::SelectionSort) {	
		Sortings::SelectionSort(array, size);
	} else if (function_name == Sortings::HeapSort) {	
		Sortings::HeapSort(array, size);
	} else {	
		Sortings::ShellSort(array, size);
	}

	std::cout << "After Sorting:  ";
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;	
	std::cout << std::endl;	
}

void Testing2(int* array, int start, int end, void (*function_name)(int*, int, int))
{
	std::cout << "Before Sorting: ";

	for (int i = 0; i <= end; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;

	if (function_name == Sortings::QuickSort) {	
		Sortings::QuickSort(array, start, end);
	} else {	
		Sortings::MergeSort(array, start, end);
	}

	std::cout << "After Sorting:  ";
	for (int i = 0; i <= end; ++i) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;	
	std::cout << std::endl;	
}

int main()
{
	/***************testing**************/
	const int n = 11;
	int array[n] = {3, 2, 6, 8, 0, 10, 0, 22, 9, 4, 5};

//	Testing1(array, n, Sortings::BubbleSort);
//	Testing1(array, n, Sortings::SelectionSort);
//	Testing1(array, n, Sortings::InsertionSort);
//	Testing1(array, n, Sortings::HeapSort);
//	Testing1(array, n, Sortings::ShellSort);

	Testing2(array, 0, n - 1, Sortings::QuickSort);
//	Testing2(array, 0, n - 1, Sortings::MergeSort);
		
	return 0;
}
