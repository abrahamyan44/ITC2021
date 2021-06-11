#include <iostream>

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int* array, int n){
	int min_idx;
	for(int i = 0; i < n - 1; ++i){
		min_idx = i;
		for(int j = i + 1; j < n; ++j)
			if(array[j] < array[min_idx])
				min_idx = j;
				Swap(&array[min_idx], &array[i]);
	}
}


void PrintSortedArray(int* array, int n) {
	for(int i = 0; i < n; ++i){
		std::cout << array[i] << " " ;
	}
	std::cout << std::endl;
}

int main() {
	int array[] = { 2, 3, 1, 5, 6, 4 };
	int n = sizeof(array) / sizeof(array[0]);
	std::cout << "Array before sorting" << std::endl;
	PrintSortedArray(array, n);
	SelectionSort(array, n);
	std::cout << "Array after selection sorting" << std::endl;
	PrintSortedArray(array, n);
	return 0;
}
