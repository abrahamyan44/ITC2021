#include <iostream>

int BinarySearch (int array[], int left, int right, int value){
	if (right >= left){
		int middle = left + ( right - left) /2;

		if ( array[middle] == value){
			return middle;
		}

		if(array[middle] > value) {
			return BinarySearch(array, left,  middle - 1, value);
		}
		return BinarySearch(array, middle + 1, right, value);
	}
	return -1;
}

int main() {
	int value;
	int array[] = {1, 34, 67, 103, 200};
	int size = sizeof(array) / sizeof(array[0]);
	std::cout << "Input element for searching" << std :: endl;
	std::cin >> value;
	if (BinarySearch(array, 0, size - 1, value) == -1) {
		std::cout << "Element is not found" << std :: endl;
	}
	else {
	std::cout << "Element is at index " << BinarySearch(array, 0, size - 1, value) << std :: endl;
	}
}
