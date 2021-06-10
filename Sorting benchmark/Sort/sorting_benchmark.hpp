#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <iomanip>
using namespace std;

template <class T>
void Swap(T* a, T* b) 
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
bool Verification (T* arr, int array_size)
{
	for(int i = 0; i < array_size - 1; i++) {
		if(arr[i] > arr[i + 1] ) {
			cout << "Wrong Sorting" << endl;
			return false;
		}  
	}
	
	return true;
}

template <class T>
void BubbleSort(T arr[], int array_size)
{
	for(int i = 0; i < array_size; i++) {
		bool swapped = false;
		for(int j = 1; j < array_size - i; j++) {
			if(arr[j] < arr[j - 1]) {
				Swap(&arr[j], &arr[j - 1]);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
}

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

void Merge(int array[], int start, int middle, int end)
{
    int left_arr_index = middle - start + 1;
    int right_arr_index = end - middle;
    int left_arr[left_arr_index];
    int right_arr[right_arr_index];

    for(int i = 0; i < left_arr_index; ++i) {
        left_arr[i] = array[start + i];
    }

    for(int j = 0; j < right_arr_index; ++j) {
        right_arr[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while(i < left_arr_index && j < right_arr_index) {
        if(left_arr[i] <= right_arr[j]) {
            array[k] = left_arr[i];
            i++;
        } else {
            array[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i < left_arr_index) {
        array[k] = left_arr[i];
        i++;
        k++;
    }

    while(j < right_arr_index) {
        array[k] = right_arr[j];
        j++;
        k++;
    }
}

void MergeSort(int array[], int start, int end) 
{
        if (start < end) {
            int middle = start + (end - start) / 2;
            MergeSort(array, start, middle);
            MergeSort(array, middle + 1, end);
            Merge(array, start, middle, end);
        }
}


template <class T>
int Partitioning(T arr[], int low, int high)
{
	int i = (low - 1);
	int pivot = arr[high];
	for(int j = low; j < high; j++) {
		if(arr[j] <= pivot) {
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}

	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}	

template <class T>
void QuickSort(T arr[], int low, int high)
{ 
	if (low < high) {
		int separate = Partitioning(arr, low, high);
		QuickSort(arr, separate + 1, high);
		QuickSort(arr, low, separate - 1);
	}
}

template <class T>
void Heapify(T arr[], int size, int i)
{ 
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if(left < size && arr[left] > arr[largest]) {
		largest = left;
	}

	if(right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	if(largest != i) {
		Swap(&arr[largest], &arr[i]);
		Heapify(arr, size, largest);
	}
}

template <class T>
void SortHeap(T arr[], int size)
{
	for(int i = size / 2 - 1; i >= 0; i--) {
		Heapify(arr, size, i);	
	}

	for(int i = size - 1; i > 0; i--) {
		Swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
	}
}

