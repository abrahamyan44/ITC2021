#include <iostream>

void Swap(int* firstElement, int* secondElement) {
	int temp = *firstElement;
	*firstElement = *secondElement;
	*secondElement = temp;
}

int Partition(int array[], int first, int last) {
	int i = (first - 1);
	int pivot = array[last];
	for(int j = first; j < last; ++j) {
		if(array[j] < pivot) {
			++i;
			Swap(&array[i], &array[j]);
		}
	}

	Swap(&array[i + 1], &array[last]);
	return (i + 1);
}

void QuickSort(int array[], int first, int last) {
	if(last >  first) {
		int pivotPlace = Partition(array, first, last);

		QuickSort(array, first, pivotPlace - 1);
		QuickSort(array, pivotPlace + 1, last);
	}
}

void Print(int array[], int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}

int main() {
	int array[] = {4, 5, 15, 2, 9, 3, 52, 1, 12, 0};
	int size = sizeof(array) / sizeof(array[0]);
	QuickSort(array, 0, size - 1);
	Print(array, size);

	return 0;
}
