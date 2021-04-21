#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


template <class T>
void Swap(T* a, T* b) 
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
bool verification (T* arr, int array_size)	
{
	for(int i = 0; i < array_size -1; i++) {
		if(arr[i] > arr[i+1] ) {
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
			if(arr[j] < arr[j-1]) {
				Swap(&arr[j], &arr[j-1]);
				swapped = true;
			}
		}
		if (swapped == false) {
				break;
		}
	}
}


template <class T>
void SelectionSort(T arr[], int size)
{
	for(int i = 0; i < size; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		Swap(&arr[i], &arr[min_index]);
	}
}
