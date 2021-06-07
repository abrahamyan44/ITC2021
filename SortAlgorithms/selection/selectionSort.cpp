#include <iostream>

void Swap(int* firstElement, int* secondElement) {
        int temp = *firstElement;
        *firstElement = *secondElement;
	*secondElement = temp;
}

void SelectionSort(int array[], int size) {
	
	for (int i = 0; i < size; ++i) {
		int minimumIndex = i;
		for(int j = i + 1; j < size; ++j) {
			if (array[j] <  array[minimumIndex]) {
				minimumIndex = j;
			}
		}
		Swap(&array[i], &array[minimumIndex]);
	}
}

void Print(int array[], int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int array[] = {4, 98, 1, 7, 56};
	int size = sizeof(array) / sizeof(array[0]);
	SelectionSort(array, size);
	Print(array, size);

        return 0;
}

