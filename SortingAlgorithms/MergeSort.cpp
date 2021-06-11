#include <iostream>

void Merge(int* array, int low, int mid, int high) {
	int temp[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while(i <= mid && j <= high) {
		if(array[i] <= array[j]) {
			temp[k] = array[i];
			++k; ++i;
		}
		else {
			temp[k] = array[j];
			++k; ++j;
		}
	}
	while(i <= mid) {
		temp[k] = array[i];
		++k; ++i;
	}
	while(j <= high) {
		temp[k] = array[j];
		++k; ++j;
	}
	for(i = low; i <= high; ++i) {
		array[i] = temp[i - low];
	}
}

void MergeSort(int* array, int low, int high) {

	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(array, low, mid);
		MergeSort(array, mid + 1, high);
		Merge(array, low, mid, high);
	}
}

void PrintArray(int* array, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] <<" ";
	}
	std::cout << std::endl;
}

int main() {
	int array[] = { 56, 23, 1, 46, 90 };
	int n = sizeof(array) / sizeof(array[0]);
	std::cout << "Array before sorting" << std::endl;
	PrintArray(array, n);
	MergeSort(array, 0, n - 1);
	std::cout << "Array after merge sorting" << std::endl;
	PrintArray(array, n);
	return 0;
}
