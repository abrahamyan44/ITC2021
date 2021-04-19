#include <iostream>

int SearchingValueWithTernarySearch(int array[], int first, int last, int value) {
	int size;
	if (last >= first) {
		int left = first + (last - first) / 3;
		int right = last - left;
		if (array[left] == value) {
			return left;
		}
		if (array[right] == value) {
			return right; 	
		}	 
		if (array[left] > value) {
			return SearchingValueWithTernarySearch(array, first, left - 1, value);
		} else if (array[right] < value) {
			return SearchingValueWithTernarySearch(array, right + 1, last, value);
		} else if (value > array[left] && value < array[right]) {
			return SearchingValueWithTernarySearch(array, left + 1, right - 1, value);
		}
	}
    return -1;
}

int main() {
    int size;
    std::cout << "Enter array's size." << std::endl;
    std::cin >> size;
    int array[size];
    std::cout << "Enter array's sorted elements separated by space." << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
    int first;
    int last;
    std::cout << "Enter interval, where you want to find value (from 0 to size - 1)." << std::endl;
    std::cin >> first;
    std::cin >> last;
    int value;
    std::cout << "Enter value which's index you want to find." << std::endl;
    std::cin >> value;
    int result = SearchingValueWithTernarySearch(array, first, last, value);
    if (result != -1) {
        std::cout << "The index of value " << value << " is: " << result << "." << std::endl;
    } else {
        std::cout << "No such element in given interval." << std::endl;
    }
    
    return 0;
}
