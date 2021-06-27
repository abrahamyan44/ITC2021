#pragma once
#include <iostream>
using namespace std;

template <class T>
void Swap(T& value1, T& value2) {
    T temporary = value1;
    value1 = value2;
    value2 = temporary;
}

template <class T>
void SortingArrayWithBubbleSort(const int& size, T* array) {
    bool swapped = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size - i; ++j) {
            if (array[j - 1] > array[j]) {
                Swap(array[j - 1], array[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
	return;
}

template <class T>
void SortingArrayWithQuickSort(int start, int wall, int end, T* array) {
    if (start >= end) {
        return;
    }
    if (start + 1 == end) {
        if (array[start] > array[end]) {
            Swap(array[start], array[end]);
        }
        return;
    }
    for (int i = wall; i < end; ++i) {
        if (array[i] < array[end]) {
            Swap(array[wall], array[i]);
            ++wall;
        }
    }
    Swap(array[wall], array[end]);
    SortingArrayWithQuickSort(start, start, wall - 1, array);
    SortingArrayWithQuickSort(wall + 1, wall + 1, end, array);
}

template <class T>
void SortingArrayWithSelectionSort(const int& size, T* array) {
    for (int i = 0; i < size; ++i) {
        int minimum = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[minimum] > array[j]) {
                minimum = j; 
            }
        }
        Swap(array[minimum], array[i]); 
    }
}

template <class T>
void SortingArrayWithInsertionSort(const int& size, T* array) {
    for (int i = 1; i < size; ++i) {
        int element = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > element) {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = element;
    }
}

template <class T>
void SortingArrayWithShellSort(const int& size, T* array) {
	for (int interval = size / 2; interval > 0; interval /= 2)	{
		for (int i = interval; i < size; ++i) {
			for (int j = i; j >= interval; j -= interval) {
				if (array[j] < array[j - interval]) {
					Swap(array[j], array[j - interval]);
				} else {
					break;
				}
			}
		}
	}
}

template <class T>
void HeapSwapping(const int& size, int index, T* array) {
	int maximum = index;
	int left = 2 * index + 1, right = 2 * index + 2;
	if (left < size && array[left] > array[maximum]) {
		maximum = left;
	}
	if (right < size && array[right] > array[maximum]) {
		maximum = right;
	}
	if (maximum != index) {
		Swap(array[maximum], array[index]);
		HeapSwapping(size, maximum, array);
	}
}

template <class T>
void SortingArrayWithHeapSort(const int& size, T* array) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		HeapSwapping(size, i, array);
	}
	for (int i = size - 1; i >= 0; --i) {
		Swap(array[0], array[i]);
		HeapSwapping(i, 0, array);
	}
}

template <class T>
void DeclareSortedArray(T* array, T* array1, T* array2, int size) {
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < size; ++i) {
		if (index2 >= size - size / 2 || (index1 < size / 2 && array1[index1] < array2[index2])) {
			array[i] = array1[index1];
			++index1;
		} else {
			array[i] = array2[index2];
			++index2;
		}
	}	
}

template <class T>
void DivideMyArray(T* array, T* array1, T* array2, int size) {
    for (int i = 0; i < size / 2; ++i) {
		array1[i] = array[i];
	}
	for (int i = 0; i < size - size / 2; ++i)	{
		array2[i] = array[i + size / 2];
	}
}

template <class T>
void SortingArrayWithMergeSort(int size, T* array) {
	if (size == 1) {
		return;
	}
	if (size == 2) {
		if (array[0] > array[1]) {
			Swap(array[0], array[1]);
		}
		return;
	}
	T* array1 = new T[size / 2];
	T* array2 = new T[size - size / 2];
	DivideMyArray(array, array1, array2, size);
	SortingArrayWithMergeSort(size / 2, array1);
	SortingArrayWithMergeSort(size - size / 2, array2);
	DeclareSortedArray(array, array1, array2, size);
	delete[] array1;
	delete[] array2;
}
