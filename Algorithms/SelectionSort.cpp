#include <iostream>
#include <iomanip>
#include <time.h>


template <typename T>
void Swap(T& first, T& second)
{
    T temp = first;
    first = second;
    second = temp; 
}

template <typename T>
void SelectionSort(T* array, int size)
{
    int min;
    for (int i = 0; i < size - 1; ++i) {
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        Swap(array[i], array[min]);
    }
}


int main()
{
    const int count = 20;
    int vector[count];
    srand(time(0));

    for (int i = 0; i < count; ++i) {
        vector[i] = rand()% 50 - 25;
        std::cout << std::setw(4) << vector[i];
    }
    std::cout << std::endl;

    SelectionSort(vector, count);

    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(4) << vector[i];
    }
    std::cout << std::endl;
}
