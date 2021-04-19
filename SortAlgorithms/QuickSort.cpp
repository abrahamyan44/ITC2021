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
    T temporary = first;
    first = second;
    second = temporary; 
}

template <typename T>
int Sort(T* array, int left, int right)
{
    int pivotIndex = right;
    int pivotValue = array[pivotIndex];
    Swap(array[left], array[pivotIndex]);
    int border = left;
    for (int i = left + 1; i <= right; ++i) {
        if (array[i] < pivotValue) {
            Swap(array[++border], array[i]);
        }
    }
    Swap(array[border], array[left]);
    return border;
}

template <typename T>
void QuickSort(T* array, int left, int right)
{
    if (left < right) {
        int pivot = Sort(array, left, right);
        QuickSort(array, left, pivot - 1);
        QuickSort(array, pivot + 1, right);
    }
}

int main()
{
    const int count = 19;
    int vector[count];
    GenerateVector(vector, count);
    PrintVector(vector, count);
    QuickSort(vector, 0, count - 1);
    PrintVector(vector, count);
}
