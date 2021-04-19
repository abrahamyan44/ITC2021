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
void Swap (T& first, T& second)
{
    T temporary = first;
    first = second;
    second = temporary; 
}

template <typename T>
void RecursivelySetRootValueLargest (T* array, int size, int parent_index)
{
    int largest_index = parent_index;
    int left = 2 * parent_index + 1;
    int right = 2 * parent_index + 2;

    if (left < size && array[left] > array[largest_index]) {
        largest_index = left;
    }
    if (right < size && array[right] > array[largest_index]) {
        largest_index = right;
    }
    if (largest_index != parent_index) {
        Swap(array[largest_index], array[parent_index]);
        RecursivelySetRootValueLargest(array, size, largest_index);
    }
}

template <typename T>
void HeapSort (T* array, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i) {
        RecursivelySetRootValueLargest(array, size, i);    
    }    
    for (int i = size - 1; i >= 0; --i) {
        Swap(array[0],array[i]);
        RecursivelySetRootValueLargest(array, i, 0);
    }
}

int main()
{
    const int count = 19;
    int vector[count];
    GenerateVector(vector, count);
    PrintVector(vector, count);
    HeapSort(vector, count);
    PrintVector(vector, count);
}
