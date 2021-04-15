#include <iostream>
#include <iomanip>
#include <time.h>


template <typename T>
void Swap(T& first, T& second)
{
    T temp = first;
    first = second;
    second = temp; 
}

template <typename T>
void QuickSort(T* array, int size)
{


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

    QuickSort(vector, count);

    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(4) << vector[i];
    }
    std::cout << std::endl;
}
