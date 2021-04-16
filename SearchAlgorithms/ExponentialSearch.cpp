#include <iostream>

int BinarySearch(int array[], int start, int end, int value) {
	if (start <= end){
		int mid = (start + end) / 2;
		if (value == array[mid])
			return mid;
		if (value < array[mid])
			return BinarySearch(array, start, mid-1, value);
		return BinarySearch(array, mid+1, end,value);
	}
	return -1;
}

int ExponentialSearch(int array[], int start, int end, int value) {
	int i = 0;
	if (value == array[0])
		return 0;
	i = 1;
	while (array[i] <= value && i < end) {
		i *= 2;
	}
	return BinarySearch(array, i / 2, std::min(i, end), value);
}

int main() {
	int array[] = {7, 10, 11, 45, 78, 100, 101};
	int size = sizeof(array) / sizeof(array[0]);
	std::cout << ExponentialSearch(array, 0, size - 1, 78); 
	std::cout << std::endl;
}
