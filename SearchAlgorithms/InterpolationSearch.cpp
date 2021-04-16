#include <iostream>

int InterpolationSearch(int array[], int start, int end, int key) {
	int pos;
	if (start <= end && key >= array[start] && key <= array[end]){
		pos = start + (((double)(end - start) / (array[end] - array[start]))
                 * (key - array[start]));
		if (key == array[pos]) {
			return pos;
		}	 
		if (key > array[pos])
			return InterpolationSearch(array, pos + 1, end, key);		
		if (key < array[pos]) {
			return InterpolationSearch(array, start, pos - 1, key);
		}

	}
	return -1;
}

int main() {
	int array[] = {1, 2, 5, 10, 78};
	std::cout << InterpolationSearch(array, 0, 4, 10) << std::endl;
}
