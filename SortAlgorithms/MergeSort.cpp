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
void InitializeArray (T* new_array, int new_size, T* old_array, int position_to_start_initializing)
{
    for (int i = 0; i < new_size; ++i) {
        new_array[i] = old_array[position_to_start_initializing + i];
    }
}

template <typename T>
void Divide (T* array, int left, int middle, int right)
{
    int first_part_size = middle - left + 1,  second_part_size = right - middle;
    T first_part[first_part_size], second_part[second_part_size];
    InitializeArray(first_part, first_part_size, array, left);
    InitializeArray(second_part, second_part_size, array, middle + 1);
    int first_index = 0, second_index = 0, index = left;
    while (first_index < first_part_size && second_index < second_part_size && index <= right) {
        if (first_part[first_index] < second_part[second_index]) {
            array[index] = first_part[first_index++];
        } else {
            array[index] = second_part[second_index++];
        }
        ++index;
    }
    while(first_index < first_part_size) {
        array[index++] = first_part[first_index++];
    }
    while(second_index < second_part_size) {
        array[index++] = second_part[second_index++];
    }
}

template <typename T>
void Merge (T* array, int left, int right)
{
    if (left >= right){
        return;
    }
    int middle = left + (right - left) / 2;
    Merge(array, left, middle);
    Merge(array, middle + 1, right);
    Divide(array, left, middle, right);
}

template <typename T>
void MergeSort (T* array, int size)
{
    Merge(array, 0, size - 1);
}

int main()
{
    const int count = 17;
    int vector[count];
    GenerateVector(vector, count);
    PrintVector(vector, count);
    MergeSort(vector, count);
    PrintVector(vector, count);
}
