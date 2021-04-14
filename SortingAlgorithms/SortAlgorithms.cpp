#include <iostream>
#include "SortAlgorithms.hpp"

void BubbleSort(int* array, int number)
{
    bool swapped;
    for(int i=0; i < number-1; i++) {
        swapped = false;
        for(int j=0; j < number-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
}

void Merge(int* array, int low, int middle, int high)
{
    int temp[high - low + 1];
    int i = low;
    int k = 0;
    int j = middle + 1;
    while(i <= middle && j <= high) {
        if(array[i] <= array[j]) {
            temp[k] = array[i++];
        } else {
            temp[k] = array[j++];
        }
        k++;
    }
    while(i <= middle) {
        temp[k++] = array[i++];
    }
    while(j <= high) {
        temp[k++] = array[j++];
    }
    for(i = low; i <= high; i++) {
        array[i] = temp[i - low];
    }
}

void MergeSort(int* array, int low, int high)
{
    if(low < high) {
        int middle = (low + high)/2;
        MergeSort(array, low, middle);
        MergeSort(array, middle + 1, high);
        Merge(array, low, middle, high);
    }
}

void SelectionSort(int* array, int size) 
{
    for(int i = 0; i < size; i++) {
        int min = i;
        for(int j = i + 1; j < size; j++) {
            if (array[min] > array[j]) {
                min = j; 
            }
        }
        swap(&array[min], &array[i]); 
    }
}

void InsertionSort(int* array, int size) 
{
    for (int i = 1; i < size; i++) {
        int element = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > element) {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = element;
    }
}

//using last element as a pivot
int PartitionArray(int* array, int low, int high)
{
    int pivot = array[high]; //choosing a pivot
    int wall = low -1;
    for(int j = low; j < high; j++) {
        if(array[j] <= pivot) {
            wall++;
            swap(&array[wall], &array[j]);
        }
    }
    swap(&array[wall + 1], &array[high]);
    return (wall + 1);
}

void QuickSort(int* array, int low, int high)
{
    if(low < high) {
        int index = PartitionArray(array, low, high - 1);
        QuickSort(array, low, index -1);
        QuickSort(array, index + 1, high);
    }
}

void Print(int* array, int number)
{
    std::cout << "The array is: ";
    for(int i=0; i < number; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int size;
    std::cout << "Input the size of array: ";
    std::cin >> size;
    int array[size];
    for(int i=0; i < size; i++) {
        std::cin >> array[i];
    }

    Print(array, size);
    std::cout << std::endl;

    BubbleSort(array, size);
    std::cout << "Bubble sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    MergeSort(array, 0, size - 1);
    std::cout << "Merge sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    SelectionSort(array, size);
    std::cout << "Selection sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    InsertionSort(array, size);
    std::cout << "Insertion sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    QuickSort(array, 0, size - 1);
    std::cout << "Quick sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    return 0;
}
