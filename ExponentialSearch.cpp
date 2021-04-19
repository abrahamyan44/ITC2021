#include <iostream>

int SearchingValueWithBinarySearch(int array[], int first, int last, int value);

int SearchingValueWithExponentialSearch(int array[], int first, int last, int value) {
    int index = 0;
    if (first <= last) {
        if (array[index] == value) {
            return index;
        }
        index = 1;
        while (array[index] < value && index <= last) {
                index = 2 * index;
        }
        return SearchingValueWithBinarySearch(array, index / 2, std::min(index, last), value);
    }
    return -1;
}

int SearchingValueWithBinarySearch(int array[], int first, int last, int value) {
	if (last >= first) {
		int middle = (first + last) / 2;
		if (value == array[middle]) {
			return middle;
		}
		if (array[middle] < value) {
			return SearchingValueWithBinarySearch(array, middle + 1, last, value); 
		}
		return SearchingValueWithBinarySearch(array, first, middle - 1, value);
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
    int result = SearchingValueWithExponentialSearch(array, first, last, value);
    if (result != -1) {
        std::cout << "The index of value " << value << " is: " << result << "." << std::endl;
    } else {
        std::cout << "No such element in given interval." << std::endl;
    }

    return 0;
}
