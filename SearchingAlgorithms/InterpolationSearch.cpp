#include <iostream>
int InpterpolationSearch(int array[], int size, int value) {
	int lo = 0, hi = (size - 1);
	while (lo <= hi && value >= array[lo] && value <= array[hi]) {
		if (lo == hi) {
			if (array[lo] == value) {
				return lo;
			}
			return -1;
		}
		int position = lo + (((double)(hi - lo) / (array[hi] - array[lo])) * (value - array[lo]));
		if (array[position] == value) {
			return position;
		}
		if (array[position] < value) {
			lo = position + 1;
		}
		else {
			hi = position - 1;
		}
	}
	return -1;
}

int main() {
	int array[] = {10, 12, 15, 67,};
	int size = sizeof(array)/sizeof(array[0]);
	int x = 12; 
	int index = InpterpolationSearch(array, size, x);
	if (index != -1) {
		std::cout << "Element found at index " << index << std :: endl;;
	}
	else {
		std::cout << "Element not found." << std :: endl;
	}
	return 0;
}


