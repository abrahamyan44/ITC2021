#include <iostream>

void Swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int array[], int start, int end) {
	int wall = start - 1;
	int pivot = array[end];
	for (int i = start; i < end; ++i) {
		if (array[i] <  pivot) {
			wall++;
			Swap(&array[i], &array[wall]);
		}
	}
	Swap(&array[wall + 1], &array[end]);
	return (wall + 1);
}

void QuickSort(int array[], int start, int end) {
	if (start < end) {
		int index = Partition(array, start, end);
		QuickSort(array, start, index - 1);
		QuickSort(array, index + 1, end);
	}
}

void Print(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i]<<" ";
	}
	std::cout << endl;
}

int main() {
	int array[]={2, 3, 4, 5, 1};
	int n = sizeof(array) / sizeof(array[0]);
	Print(array, n);
	QuickSort(array, 0, n-1);
	Print(array, n);
	return 0;
}
