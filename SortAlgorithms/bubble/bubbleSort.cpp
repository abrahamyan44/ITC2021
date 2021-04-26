#include <iostream>

void Swap(int* firstElement , int* secondElement) {
	int temp = *firstElement;
	*firstElement = *secondElement;
	*secondElement = temp;
}

void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (array[j] > array[j + 1]) {
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void Print(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}

int main() {
	int arr[] = {5, 96, 8, 76, 0};
	int size = sizeof(arr)/sizeof(arr[0]);
	BubbleSort(arr, size);
	Print(arr, size);

	return 0;
}
