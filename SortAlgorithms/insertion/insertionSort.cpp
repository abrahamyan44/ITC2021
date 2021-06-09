#include <iostream>

void Swap(int* firstElement, int* secondElement) {
	int temp = *firstElement;
	*firstElement = *secondElement;
	*secondElement = temp;
}

void InsertionSort(int array[], int size) {
	for (int i = 1; i < size; ++i) {
		int j = i - 1;
		while (j >= 0 && array[j] > array[i]) {
			Swap(&array[j], &array[i]);
			j = j - 1;
			i = i - 1;
		}
	}
}

void Print(int array[], int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int array[] = {4, 78, 5, 0, 4, 15, 7, 6, 1, 35};
	int size = sizeof(array) / sizeof(array[0]);
	InsertionSort(array, size);
	Print(array, size);

	return 0;
}
