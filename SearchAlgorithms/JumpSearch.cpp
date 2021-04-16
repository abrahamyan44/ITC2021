#include <iostream>
#include <cmath>

int JumpSearch(int* array, int size, int value) {
	int pos = sqrt(size);
	int i = 0;
	while (array[pos] <= value && pos < size) {
		i = pos;
		pos += sqrt(size);
		if (pos > size-1)
			return -1;
	}
	for (int j = i; j < pos; ++j) {
		if (array[j] == value) {
			return j;
		}
	}
	return -1;
}

int main() {
	int array[] = {3, 5, 8, 10, 25, 100};
	int size = sizeof(array) / sizeof(array[0]);
	int index = JumpSearch(array, 6, 10);
	std::cout << "index = " << index << std::endl;
}
