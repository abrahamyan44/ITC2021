#include <iostream>

int SearchingValueWithBinarySearch (int array[], int first, int last, int element) {
	if (last >= first) {
		int middle = (first + last) / 2;
		if (element == array[middle]) {
			return middle;
		}
		if (array[middle] < element) {
			return SearchingValueWithBinarySearch(array, middle + 1, last, element); 
		}
		return SearchingValueWithBinarySearch(array, first, middle - 1, element);
	}
	return -1;
}

int main () {
	int size;
	std::cout << "Enter array's size." << std::endl;
	std::cin >> size;
	int array[size];
	std::cout << "Enter array's sorted elements separated by spaces." << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cin >> array[i];
	}

	int element;
	int result;
	std::cout << "Enter element which's index you want to know." << std::endl;
	std::cin >> element;
	result = SearchingValueWithBinarySearch(array, 0, size - 1, element);
	if (result != -1) {
		std::cout << "Inputed element's index is: " << result << std::endl;
	}
	else {
		std::cout << "No such element." << std::endl;
	}

	return 0;
}
