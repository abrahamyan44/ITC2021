#include <iostream>

int SearchingValueWithInterpolationSearch(int array[], int first, int last, int value) {
    int size;
    int index;
    if (first <= last) {
        int index = first + ((value - array[first]) * (last - first)) / (array[last] - array[first]);
        if (array[index] == value) {
            return index;
        }
        if (array[index] < value) {
            first = index + 1;
            return SearchingValueWithInterpolationSearch(array, first, last, value);
        } else {
            last = index - 1;
            return SearchingValueWithInterpolationSearch(array, first, last, value);
        }
    return -1;
    }
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
    int result = SearchingValueWithInterpolationSearch(array, first, last, value);
    if (result != -1) {
        std::cout << "The index of value " << value << " is: " << result << "." << std::endl;
    } else {
        std::cout << "No such element in given interval." << std::endl;
    }

    return 0;
}
