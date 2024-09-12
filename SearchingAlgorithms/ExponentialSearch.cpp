#include <iostream>

int BinarySearch(int array[], int, int , int);

int ExponentialSearch(int array[], int size, int value){
	if (array[0] == value){
		return 0;
	}
	int i = 1;
	while (i < size && array[i] <= value) {
		i = i * 2;
	}
	return BinarySearch(array, i / 2, std::min(i, size - 1), value);
}

int BinarySearch(int array[], int left, int right, int value) {
	if(right >= left) {
		int middle = left + ( right - left) / 2;
		if(array[middle] == value){
			return middle;
		}
		if(array[middle] > value) {
			return BinarySearch(array, left, middle - 1, value);
		}
		return BinarySearch(array, middle + 1, right, value);
		}
	return -1;
}

int main() {
	int value;
	int array[] = { 1, 23, 45, 78, 90 };
	int size = sizeof(array) / sizeof(array[0]);
	std::cout << "Input element " << std :: endl;
	std::cin >> value;
	int result = ExponentialSearch(array, size, value);
	if (result == -1) {
		std::cout << "Element is not found" << std::endl;
	} else {
		std::cout << "Element is at index " << result << std::endl;
	}
	return 0;
}

