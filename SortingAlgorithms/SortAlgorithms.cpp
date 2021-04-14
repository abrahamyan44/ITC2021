#include <iostream>
#include "SortAlgorithms.hpp"

void SortArrayUsingBubbleSort (int* array, int number)
{
    bool swapped;
    for (int i=0; i < number-1; i++) {
        swapped = false;
        for (int j=0; j < number-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

void Merge (int* array, int low, int middle, int high)
{
    int temporal[high - low + 1];
    int i = low;
    int k = 0;
    int j = middle + 1;
    while (i <= middle && j <= high) {
        if (array[i] <= array[j]) {
            temporal[k] = array[i++];
        } else {
            temporal[k] = array[j++];
        }
        k++;
    }
    while (i <= middle) {
        temporal[k++] = array[i++];
    }
    while (j <= high) {
        temporal[k++] = array[j++];
    }
    for (i = low; i <= high; i++) {
        array[i] = temp[i - low];
    }
}

void SortArrayUsingMergeSort (int* array, int low, int high)
{
    if (low < high) {
        int middle = (low + high)/2;
        SortArrayUsingMergeSort(array, low, middle);
        SortArrayUsingMergeSort(array, middle + 1, high);
        Merge(array, low, middle, high);
    }
}

void SortArrayUsingSelectionSort (int* array, int size) 
{
    for (int i = 0; i < size; i++) {
        int minimum = i;
        for (int j = i + 1; j < size; j++) {
            if (array[minimum] > array[j]) {
                minimum = j; 
            }
        }
        swap(array[minimum], array[i]); 
    }
}

void InsertionSort (int* array, int size) 
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
int DivideArray (int* array, int low, int high)
{
    int pivot = array[high]; //choosing a pivot
    int wall = low -1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            wall++;
            swap(array[wall], array[j]);
        }
    }
    swap(array[wall + 1], array[high]);
    return (wall + 1);
}

void SortArrayUsingQuickSort (int* array, int low, int high)
{
    if (low < high) {
        int index = DivideArray(array, low, high - 1);
        SortArrayUsingQuickSort(array, low, index -1);
        SortArrayUsingQuickSort(array, index + 1, high);
    }
}

void Print (int* array, int number)
{
    std::cout << "The array is: ";
    for (int i=0; i < number; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int size;
    std::cout << "Input the size of array: ";
    std::cin >> size;
    std::cout << "\nPlease input array's elements:\n";
    int array[size];
    
    for (int i=0; i < size; i++) {
        std::cin >> array[i];
    }

    Print(array, size);
    std::cout << std::endl;

    SortArrayUsingBubbleSort(array, size);
    std::cout << "Bubble sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    SortArrayUsingMergeSort(array, 0, size - 1);
    std::cout << "Merge sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    SortArrayUsingSelectionSort(array, size);
    std::cout << "Selection sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    SortArrayUsingInsertionSort(array, size);
    std::cout << "Insertion sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    SortArrayUsingQuickSort(array, 0, size - 1);
    std::cout << "Quick sorted array: \n";
    Print(array, size);
    std::cout << std::endl;

    return 0;
}
