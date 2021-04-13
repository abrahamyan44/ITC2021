#include <iostream>
#include <iomanip>
#include <time.h>


template <typename T>
void Divide(T* array, int left, int middle, int right)
{
    int first_part_size = middle - left + 1;
    int second_part_size = right - middle;
    T first_part[first_part_size];
    T second_part[second_part_size];
    
    for (int i = 0; i < first_part_size; ++i) {
        first_part[i] = array[left + i];
    }
    for (int i = 0; i < second_part_size; ++i) {
        second_part[i] = array[middle + i];
    }
    
    int first_index = 0, second_index = 0, index = 0;
    while (first_index < first_part_size && 
            second_index < second_part_size && index < right) {
        if (first_part[first_index] < second_part[second_index]) {
            array[index] = first_part[first_index];
            ++first_index;
            ++index;
        } else {
            array[index] = second_part[second_index];
            ++second_index;
            ++index;
        }
    }
    while(first_index < first_part_size) {
        array[index] = first_part[first_index];
        ++index;
        ++first_index;
    }
    while(second_index < second_part_size) {
        array[index] = second_part[second_index];
        ++index;
        ++second_index;
    }
}

template <typename T>
void Merge(T* array, int left, int right)
{
    if (left >= right){
        return;
    }
    int middle = left + (left + right) / 2;
    Merge(array, left, middle);
    Merge(array, middle + 1, right);
    Divide(array, left, middle, right);
}

template <typename T>
void MergeSort(T* array, int size)
{
    Merge(array, 0, size - 1);
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

    MergeSort(vector, count);

    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(4) << vector[i];
    }
    std::cout << std::endl;
}
