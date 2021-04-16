#include <iostream>

int TernarySearch(int array[], int start, int end, int element) {
	if (start < end){
		int middle1 = start + (end - start) / 3;
		int middle2 = end - (end - start) / 3;
		if (array[middle1] == element) {
			return middle1;
		}
		if (array[middle2] == element) {
			return middle2;
		}
		if (element < array[middle1]) {
			return TernarySearch(array, start, middle1 - 1, element);
		}
		if (element > array[middle2]) {
			return TernarySearch(array, middle2 + 1, end, element);
		}
		return TernarySearch(array, middle1 + 1, middle2 -1, element);
	} else {
		return -1;
	}

}

int main() {
	int array[] = {1, 3, 5, 10, 72, 100};
	std::cout << TernarySearch(array, 0, 5, 10) << std::endl;
}




