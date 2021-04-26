#include <iostream>
#include <cmath>
#include <cassert>

int SearchItem(int array[], int size, int item)
{
    int step = sqrt(size);
    int prev = 0;

    while (step < size && array[step] <= item) {
        prev = step;
        step += sqrt(size);

        if (step >= size) {
            return -1;
        }
    }

    for (int j = prev; j < step; ++j) {
        if (array[j] == item) {
            return j;
        }
    }

    return -1;
} 

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    std::cout << "Searched item index is ";
    std::cout << SearchItem(arr, 5, 3) << std::endl;

    return 0;
}

