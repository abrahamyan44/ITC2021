#include <iostream>

void InsertionSort(int array[], int size) {
    for (int i = 1; i < size; ++i) {
        int element = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > element) {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = element;
    }
}

void Print(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
}

int main() {
    int size;
    std::cin >> size;
    int array[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
    InsertionSort(array, size);
    Print(array, size);
    return 0;
}
