#include <iostream>
#include <iomanip>
#include <time.h>

template <typename T>
void GenerateVector (T* array, int size)
{
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        array[i] = rand()% 50 - 25;
    }
}

template <typename T>
void PrintVector (T* array, int size)
{ 
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << array[i];
        std::cout << ",";
    }
    std::cout << std::endl;
}

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
    int index_min_element;
    for (int i = 0; i < size - 1; ++i) {
        index_min_element = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[index_min_element] > array[j]) {
                index_min_element = j;
            }
        }
        Swap(array[i], array[index_min_element]);
    }
}

int main()
{
    const int count = 20;
    int vector[count];
    GenerateVector(vector,count);
    PrintVector(vector, count);
    SelectionSort(vector, count);
    PrintVector(vector, count);
}