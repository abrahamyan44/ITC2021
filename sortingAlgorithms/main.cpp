#include <iostream>

#include "Sortings.hpp"

int main()
{
	/***************testing**************/
	const int n = 11;
	int array[n] = {3, 2, 6, 8, 0, 10, 0, 22, 9, 4, 5};

	std::cout << "Before Sorting: ";
	for (int element : array) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	/*Sortings::BubbleSort(array,n);

	std::cout << "After Bubble Sort: ";
	for (int element : array) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;*/
	
	/*************************************/
	
	/*Sortings::SelectionSort(array,n);

	std::cout << "After Selection Sort: ";
	for (int element : array) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;*/

	/*************************************/

	Sortings::InsertionSort(array,n);

	std::cout << "After Insertion Sort: ";
	for (int element : array) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;
	
	/*************************************/

	return 0;
}
