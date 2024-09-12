#include <iostream>

int TeranrySearch(int left, int right, int key, int array[]) {
	if (right >= left) {
		int middle1 = left + (right - left) / 3;
		int middle2 = right - (right - left) / 3;
		if(array[middle1] == key) {
			return middle1;
		}
		if(array[middle2] == key) {
			return middle2;
		}

		if(key < array[middle1]) {
			return TeranrySearch(left, middle1 - 1, key, array);
		} else {
			return TeranrySearch(middle2 + 1, right, key, array);
		}
	}
	return -1;
}

int main() {
	int  key;
	int array[] = { 2, 4, 6, 8, 10, 34, 200 };
	int size = sizeof(array) / sizeof(array[0]); 
	std::cout << "Input element" << std::endl;
	std::cin >> key; 
	int result = TeranrySearch(0, size - 1, key, array);
	if(result == -1) { 
		std::cout << "Element is not found" << std::endl;
	} else {
		std::cout << "Element is at index" << result << std::endl;
	}
	return 0;
}


