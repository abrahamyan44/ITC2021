#include <iostream>
#include "SearchAlgorithms.hpp"
#include <math.h>

int FindElementUsingLinearSearch (int* array, int size, int unknown)
{
	for (int i = 0; i < size; i++) {
		if (array[i] == unknown) {
			return i;
		}
	}
    return -1;
}

int FindElementUsingBinarySearch (int* array, int left, int right, int unknown)
{
    if (right >= left) {
        int middle = left + (right - left)/2;
        if (array[middle] == unknown) {
            return middle;
        }
        if (array[middle] > unknown) {
            return FindElementUsingBinarySearch(array, left, middle - 1, unknown);
        } else {
            return FindElementUsingBinarySearch(array, middle + 1, right, unknown);
        }
    }
    return -1;
}

int FindElementUsingInterpolationSearch (int* array, int low, int high, int unknown)
{
    int index;
    if (low <= high && unknown >= array[low] && unknown <= array[high]) {
        index = low + (((double)(high - low) / (array[high] - array[low])) 
                        * (unknown - array[low]));
        if (array[index] == unknown) {
            return index;
        }
        if (array[index] < unknown) {
            return FindElementUsingInterpolationSearch(array, index + 1, high, unknown);
        }
        if (array[index] > unknown) {
            return FindElementUsingInterpolationSearch(array, low, index - 1, unknown);
        }
    }
    return -1;
}

int FindElementUsingJumpSearch (int* array, int size, int unknown)
{
    int step = sqrt(size);
	int index = 0;
    //for finding interval where the search should be done
	while (array[std::min(step, size) - 1] < unknown) {
		index = step;
		step += sqrt(size);
		if (index >= size) {
			return -1;
		}
	} //working inside interval
	while (array[index] < unknown) {
		index++;
		if (index == std::min(step, size)) {
			return -1;
		}
	} //linear search
	if (array[index] == unknown) {
		return index;
	}
	return -1;
}

int FindElementUsingTernarySearch (int* array, int start, int end, int unknown)
{
    if (start <= end) {
        int middle1 = start + (end - start) / 3;
        int middle2 = end - (end - start) / 3;
        if (array[middle1] = unknown) {
            return middle1;
        }
        if (array[middle2] = unknown) {
            return middle2;
        }
        if (array[middle1] > unknown) {
            return FindElementUsingTernarySearch(array, start, middle1 - 1, unknown);
        } else if (array[middle2] < unknown) {
            return FindElementUsingTernarySearch(array, middle2 + 1, end, unknown);
        } else {
            return FindElementUsingTernarySearch(array, middle1 + 1, middle2 - 1, unknown);
        }
    }
    return -1;
}

int FindElementUsingExponentialSearch (int* array, int size, int unknown) 
{
    if (array[0] == unknown) {
        return 0;
    }
    int i = 1;
    while (i < size && array[i] <= unknown) {
        i *= 2;
    }
    return FindElementUsingBinarySearch(array, i / 2, std::min(i, size - 1), unknown);
}

int main()
{
	int size;
	std::cout << "Please enter size of the array:\n";
	std::cin >> size;

	int array[size];
	std::cout << "Please enter sorted array's elements:\n";
	for (int i = 0; i < size; i++) {
		std::cin >> array[i];
	}

	int index1 = FindElementUsingLinearSearch(array, size, 9);
    std::cout << "Linear Search: ";
	if (index1 == -1) {
		std::cout << "The element isn't in array!\n";
	} else {
		std::cout << "The index of the searchable element is " << index1 << std::endl;
	}

    int index2 = FindElementUsingBinarySearch(array, 0, size - 1, 99);
    std::cout << "Binary Search: ";
    if (index2 == -1) {
        std::cout << "The element isn't in array!\n";
    } else {
        std::cout << "The index of the searchable element is " << index2 << std::endl;
    }
                                                                                    
    int index3 = FindElementUsingInterpolationSearch(array, 0, size - 1, 999);
    std::cout << "Interpolation Search: ";
    if (index3 == -1) {
        std::cout << "The element isn't in array!\n";
    } else {
        std::cout << "The index of the searchable element is " << index3 << std::endl;
    }

    int index4 = FindElementUsingTernarySearch(array, 0, size - 1, -3);
    std::cout << "Ternary Search: ";
    if (index4 == -1) {
        std::cout << "The element isn't in array!\n";
    } else {
        std::cout << "The index of the searchable element is " << index4 << std::endl;
    }

    int index5 = FindElementUsingExponentialSearch(array, size, 33);                  
    std::cout << "Exponential Search: ";
    if (index5 == -1) {
        std::cout << "The element isn't in array!\n";
    } else {
        std::cout << "The index of the searchable element is " << index5 << std::endl;
    }

	int index6 = FindElementUsingJumpSearch(array, size, 333);
    std::cout << "Jump Search: ";
	if (index6 == -1) {
		std::cout << "The element isn't in array!\n";
	} else {
		std::cout << "The index of the searchable element is " << index6 << std::endl;
    }

	return 0;
}
