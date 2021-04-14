#include <iostream>

void BubbleSort(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j + 1] < array[j]) {
                int temp;
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
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
    BubbleSort(array, size);
    Print(array, size);
    return 0;
}
