#include <cassert>
#include <iostream>
#include "Sortings.hpp"

namespace 
{
	void Swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}	
}

void Sortings::BubbleSort(int* array, int size)
{
	bool is_sorted = true;
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				is_sorted = false;
				Swap(array[j],array[j + 1]);
			}
		}

		if (is_sorted) {
			return;
		}
	}
}

void Sortings::SelectionSort(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i) {
		int min_index = i;
		for (int j = i + 1; j < size; ++j) {
			if (array[j] < array[min_index]) {
				min_index = j;
			}
		}

		//if it is not the same element
        if (i != min_index) {
            // Swap the found min element with the first element
		    Swap(array[min_index],array[i]);
	    }
    }
}

void Sortings::InsertionSort(int* array, int size)
{
	for (int i = 1; i < size; ++i) {
		int tmp = array[i], j = i - 1;
		while (j >= 0 && array[j] > tmp) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = tmp;
	}
}

namespace
{	
	void Merge(int* array, int start, int middle, int end)
	{
		int i = start; 			 // initial index of first subarray
		int j = middle + 1;		 // initial index of second subarray
		int l = end - start + 1; // size of temp array

		int* tmp = new int[l];

		for (int k = 0; k < l; ++k) {
			if ((i <= middle && array[i] < array[j]) || j > end) {
				tmp[k] = array[i];
				++i;
			} else {
				tmp[k] = array[j];
				++j;
			}
		}

		for (int k = 0, p = start; k < l; ++k, ++p) {
			array[p] = tmp[k];
		}
		delete[] tmp;
	}
}

void Sortings::MergeSort(int* array, int start, int end)
{
	if (start >= end) {
		return;
	}

	int middle = (start + end) / 2;

	MergeSort(array, start, middle);
	MergeSort(array, middle + 1, end);
	Merge(array, start, middle, end);
}


