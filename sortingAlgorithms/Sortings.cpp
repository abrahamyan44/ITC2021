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
	bool sorted = true;
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				sorted = false;
				Swap(array[j],array[j + 1]);
			}
		}

		if (sorted) {
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
		// Swap the found min element with the first element
		Swap(array[min_index],array[i]);
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

//void Sortings::QuickSort
