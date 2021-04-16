#include <iostream>

int BinarySearch(int* array, int start, int end, int key) {
	int mid_index = (start + end) / 2;
	if (start <= end){
		if (key == array[mid_index]) {
			return mid_index;
		}	 
		if (key < array[mid_index]) {
			return BinarySearch(array, start, mid_index - 1, key);
		}
		return BinarySearch(array, mid_index + 1, end, key);		
	}
	return -1;
}

int main() {
	int array[] = {1, 2, 5, 10, 78};
	std::cout << BinarySearch(array, 0, 4, 10);
}
