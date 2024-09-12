#include <iostream>

int LinearSearch(int array[], int size, int value) {
	for (int i = 0; i < size; ++i) {
			if(array[i] == value) {
				return i;
			}
		}
		return -1;
}

int main() {
	int array[] = { 2, 45 , 12, 90, 35};
	int value;
	int size = sizeof(array) / sizeof(array[0]);
	std::cout << "Input element" << std::endl;
	std::cin >> value;
	int result = LinearSearch(array, size, value);
	if(result == -1) {
		std::cout << "Element is not found" << std::endl;
	} else {
		std::cout << "Element is at index " << result << std::endl;
	}
	return 0;
}

