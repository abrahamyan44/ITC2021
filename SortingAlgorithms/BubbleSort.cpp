#include <iostream>

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int array[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; ++i){
		std::cout << array[i] << " ";
	}
		std::cout << std::endl;
}

int main() {
	int array[] = { 5, 9 , 23, 67, 0, 12 };
	int n = sizeof(array) / sizeof(array[0]);
	std::cout << "Array before sorting " << std::endl;
	PrintArray(array, n);
	BubbleSort(array, n);
	std::cout << "Array after Bubble sorting " << std::endl;
	PrintArray(array, n);
	return 0;
}
