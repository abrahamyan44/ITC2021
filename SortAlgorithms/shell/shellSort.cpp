#include <iostream>

void ShellSort(int arr[], int size)
{
    for(int gap = size / 2; gap > 0; gap = gap / 2) {
        for(int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && temp < arr[j - gap]; j = j - gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void Print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{   int size;
    int arr[] = {2, 4, 14, 9, 3, 6, 29, 7};
    size = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, size);
    Print(arr, size);

    return 0;
}
