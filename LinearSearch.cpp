#include <iostream>

int SearchingValueWithLinearSearch (int array[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return i;
        } 
    }
            return -1;
}

int main () {
    int size;
    std::cout << "Enter array's size." << std::endl;
    std::cin >> size;
    int array[size];
    std::cout << "Enter array's elements separated by spaces." << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
    int element;
    std::cout << "Enter value which's index you want to find." << std::endl;
    std::cin >> element;
    int result = SearchingValueWithLinearSearch(array, size, element);
        if (result != -1) {
        std::cout << "Element's index is: " << SearchingValueWithLinearSearch(array, size, element) << std::endl;
    } else {
        std::cout << "No such element." << std::endl;
    }
    return 0;
}
