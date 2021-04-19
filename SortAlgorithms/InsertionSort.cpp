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
void InsertionSort(T* array, int size)
{
    for (int i = 1; i < size; ++i) {
        T temporary = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > temporary) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = temporary;
    }
}

int main()
{
    const int count = 20;
    int vector[count];
    GenerateVector(vector, count);
    PrintVector(vector, count);
    InsertionSort(vector, count);
    PrintVector(vector, count);
}
