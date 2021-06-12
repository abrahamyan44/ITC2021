#include <iostream>
#include <cmath>

int JumpSearch(int array[], int size, int value) {
	int step = sqrt(size);
	int prev = 0;
	while (array[prev] < value) {
		prev++;
		if(prev == std::min(step, size)){
			return -1;
		}
	}
	if(array[prev] == value){
			return prev;
	}
		return -1;
}


int main() {
	int array[] = { 12, 45, 67, 89 };
	int size = sizeof(array) / sizeof(array[0]);
	int value;
	std::cout << "Input element" << std::endl;
	std::cin >> value;
	int result = JumpSearch(array, size, value);
	if(result == -1){
		std::cout << "Element is not found" << std::endl;
	} else {
		std::cout << "Element is at index " << result << std::endl;
	}
	return 0;
}
