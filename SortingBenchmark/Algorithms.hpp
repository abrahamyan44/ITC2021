#include <iostream>

template <typename T>
void Swap (T& first, T& second)
{
    T temporary = first;
    first = second;
    second = temporary; 
}

//========Heap sort========
template <typename T>
void RecursivelySetRootValueLargest (T* array, int size, int parent_index)
{
    int largest_index = parent_index;
    int left = 2 * parent_index + 1;
    int right = 2 * parent_index + 2;
    if (left < size && array[left] > array[largest_index]) {
        largest_index = left;
    }
    if (right < size && array[right] > array[largest_index]) {
        largest_index = right;
    }
    if (largest_index != parent_index) {
        Swap(array[largest_index], array[parent_index]);
        RecursivelySetRootValueLargest(array, size, largest_index);
    }
}

template <typename T>
void HeapSort (T* array, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i) {
        RecursivelySetRootValueLargest(array, size, i);    
    }    
    for (int i = size - 1; i >= 0; --i) {
        Swap(array[0],array[i]);
        RecursivelySetRootValueLargest(array, i, 0);
    }
}

//========Insertion sort======
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

//=======Merge sort=======
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

//=======Quick sort======
template <typename T>
int Sort(T* array, int left, int right)
{
    int pivotIndex = right;
    int pivotValue = array[pivotIndex];
    Swap(array[left], array[pivotIndex]);
    int border = left;
    for (int i = left + 1; i <= right; ++i) {
        if (array[i] < pivotValue) {
            Swap(array[++border], array[i]);
        }
    }
    Swap(array[border], array[left]);
    return border;
}

template <typename T>
void QuickSortRecursively(T* array, int left, int right)
{
    if (left < right) {
        int pivot = Sort(array, left, right);
        QuickSortRecursively(array, left, pivot - 1);
        QuickSortRecursively(array, pivot + 1, right);
    }
}

template <typename T>
void QuickSort(T* array, int size)
{
    QuickSortRecursively(array, 0, size - 1);
}

//======Selection sort=======
template <typename T>
void SelectionSort(T* array, int size)
{
    int index_min_element;
    for (int i = 0; i < size - 1; ++i) {
        index_min_element = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[index_min_element] > array[j]) {
                index_min_element = j;
            }
        }
        Swap(array[i], array[index_min_element]);
    }
}

//=========Shell sort=========
template <typename T>
void ShellSort (T* array, int size)
{
    for (int gap = size / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temporary = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temporary; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temporary;
        }
    }
}

