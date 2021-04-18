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
int InterpolationSearch(T wanted_number, T* array, int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end && wanted_number >= array[start] && wanted_number <= array[end]) {
        if(start == end) {
            if (wanted_number == array[end]) {
                return end;
            }
            return -1;
        }
        int possition = static_cast<float>(start + (wanted_number - array[start]) * (end - start) / (array[end] - array[start]));
        if (wanted_number == array[possition]) {
            return possition;
        }
        if(wanted_number < array[possition]) {
            end = possition - 1;
        } else {
            start = possition + 1;
        }
    }
    return -1;
}

int main()
{
    const int count = 19;
    int vector[count]; // = {-24, -23, -20, -20, -19, -18, -15, -13,  -5,  -4,  -2,   4,   6,   6,   7,   8,  13,  16,  19}; 
    int number = -5;

    GenerateVector(vector, count);
    //PrintVector(vector, count);
    InsertionSort(vector, count);
    PrintVector(vector, count);
    int result = InterpolationSearch(number, vector, count);
    if (-1 == result) {
        printf("Number %d not found.\n", number);
    } else {
        printf("The index of %d is %d.\n", number, result);
    }
}
