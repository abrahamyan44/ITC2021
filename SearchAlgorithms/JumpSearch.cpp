#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>

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
int JumpSearch(T wanted_number, T* array, int size)
{
    int step = sqrt(size);
    int jump_index = 0, previous_jump_index = 0;
    for ( ; jump_index < size && array[std::min(jump_index, size)] < wanted_number; jump_index += step) {
        previous_jump_index = jump_index;
    }
    if (wanted_number == array[jump_index]) {
        return jump_index;
    }
    for(int i = previous_jump_index; i <= std::min(jump_index, size - 1); ++i) {
        if (wanted_number == array[i]) {
            return i;
        }
    }
    return -1;
}

int main()
{
    const int count = 19;
    int vector[count];// = {-24, -23, -20, -20, -19, -18, -15, -13,  -5,  -4,  -2,   4,   6,   6,   7,   8,  13,  16,  19}; 
    int number = 30;
    GenerateVector(vector, count);
    //PrintVector(vector, count);
    InsertionSort(vector, count);
    PrintVector(vector, count);
    int result = JumpSearch(number, vector, count);
    if (-1 == result) {
        printf("Number %d not found.\n", number);
    } else {
        printf("The index of %d is %d.\n", number, result);
    }
}
