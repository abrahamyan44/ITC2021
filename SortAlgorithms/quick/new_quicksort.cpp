#include <iostream>
using namespace std;

void Swap(int* firstElement, int* secondElement) {
	cout << "swap" << endl;
	int temp = *firstElement;
	*firstElement = *secondElement;
	*secondElement = temp;
}

int Partition(int array[], int first, int last) {
	cout << "partition" << endl;
	int i = (first - 1);
	int pivot = array[last];
	for(int j = first; j < last; ++j) {
		cout << "for in" << endl;
		if(array[j] < pivot) {
			++i;
			Swap(&array[i], &array[j]);
		}
	}
	cout << "for out" << endl;
	Swap(&array[i + 1], &array[last]);
	return (i + 1);
}

void QuickSort(int array[], int first, int last) {
		cout << "quicksort" << endl;
	if(last >  first) {
		int pivotPlace = Partition(array, first, last);

		Partition(array, first, pivotPlace - 1);
		Partition(array, pivotPlace + 1, last);
	}
}

void Print(int array[], int size) {
	cout<< "print" << endl;
	for(int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}

int main() {
	cout << "main" << endl;
	int array[] = {4, 5, 15, 2, 9, 3};
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	QuickSort(array, 0, size - 1);
	Print(array, size);

	return 0;
}
