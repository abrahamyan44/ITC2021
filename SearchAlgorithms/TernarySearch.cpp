#include <iostream>
#include <iomanip>
#include <time.h>

template <typename T>
void GenerateVector(T* array, int size)
{
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        array[i] = rand()% 50 - 25;
    }
}

template <typename T>
void PrintVector(T* array, int size)
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

template <typename T>
int TernarySearch(T wanted_number, T* array, int start, int end)
{
    if (start <= end) { 
        int middle1 = start + (end - start) / 3;
        int middle2 = end - (end - start) / 3;
        if (wanted_number == array[middle1]) {
            return middle1;
        }
        if (wanted_number == array[middle2]) {
            return middle2;
        }
        if (wanted_number < array[middle1]) {
            return TernarySearch(wanted_number, array, start, middle1 - 1);
        }
        if (wanted_number  > array[middle2]) {
            return TernarySearch(wanted_number, array, middle2 + 1, end);
        }
        return TernarySearch(wanted_number, array, middle1 + 1, middle2 - 1);
    }
    return -1;
}

int main()
{
    const int count = 20;
    int vector[count]; // = {-24, -23, -20, -20, -19, -18, -15, -13,  -5,  -4,  -2,   4,   6,   6,   7,   8,  13,  16,  19}; 
    int number = 8;

    GenerateVector(vector, count);
    //PrintVector(vector, count);
    InsertionSort(vector, count);
    PrintVector(vector, count);
    int result = TernarySearch(number, vector, 0, count - 1);
    if (-1 == result) {
        printf("Number %d not found.\n", number);
    } else {
        printf("The index of %d is %d.\n", number, result);
    }
}
