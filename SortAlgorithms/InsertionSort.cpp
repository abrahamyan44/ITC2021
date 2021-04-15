#include <iostream>
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

    InsertionSort(vector, count);

    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(4) << vector[i];
    }
    std::cout << std::endl;
}
