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
void ShellSort (T* array, int size)
{
    for (int gap = size / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temporary = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temporary; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temporary;
        }
    }
}

int main()
{
    const int count = 20;
    int vector[count];
    GenerateVector(vector, count);
    PrintVector(vector, count);
    ShellSort(vector, count);
    PrintVector(vector, count);
}
