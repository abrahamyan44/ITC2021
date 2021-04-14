#include <iostream>

void Swap(int& value1, int& value2) {
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void SelectionSort(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        int minimum = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[minimum] > array[j]) {
                minimum = j; 
            }
        }
        Swap(array[minimum], array[i]); 
    }
}

void Print(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    int size;
    std::cout << "Enter array's size." << std::endl;
    std::cin >> size;
    std::cout << "Enter array's elements separated by spaces." << std::endl;
    int array[size];
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    SelectionSort(array, size);
    Print(array, size);
    return 0;
}
