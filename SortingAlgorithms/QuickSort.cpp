#include <iostream>

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int array[], int low, int high) {
	int pivot = array[high];
	int wall = (low - 1);
	for (int j = low; j <= high - 1; ++j) {
		if (array[j] < pivot) {
			++wall;
			Swap(&array[wall], &array[j]);
		}
	}
	Swap(&array[wall + 1], &array[high]);
	return (wall + 1);
}

void QuickSort(int array[], int low, int high) {
	if (low < high){
		int p = Partition(array, low, high);
		QuickSort(array, low, p - 1);
		QuickSort(array, p + 1, high);
	}
}

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout <<array[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int array[] = { 45, 89, 12, 0, 9, 34 };
	int n = sizeof(array) / sizeof(array[0]);
	std::cout << "Array before sorting" << std::endl;
	PrintArray(array, n);
	QuickSort(array, 0, n - 1);
	std::cout << "Array after quick sorting" << std::endl;
	PrintArray(array, n);
	return 0;
}
