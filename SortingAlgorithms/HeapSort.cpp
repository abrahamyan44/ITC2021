#include <iostream>

void Heapify(int* array, int size, int i) {
	int largest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if (left < size && array[left] > array[largest]) {
		largest = left;
	}
	if (right < size && array[right] > array[largest]) {
		largest = right;
	}
	if (largest != i) {
		std::swap(array[i], array[largest]);
		Heapify(array, size, largest);
	}
}

void HeapSort(int* array, int size) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		Heapify(array, size, i);
	}

	for (int i = size - 1; i > 0; --i) {
		std::swap(array[0], array[i]);
		Heapify(array, i, 0);
	}
}

void PrintArray(int* array, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	int array[] = { -12, 121, -13, -5, 6, 7 };
	int size = sizeof(array) / sizeof(array[0]);
	std::cout << "Array before sorting" << std::endl;
	PrintArray(array, size);
	HeapSort(array, size);
	std::cout << "Array after heap sorting" << std::endl;
	PrintArray(array, size);
}

