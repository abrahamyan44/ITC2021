#include <iostream>
using namespace std;

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Heapify(int* array, int size, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	i = largest;
	if (l < size && array[l] > array[largest]) {
		largest = l;
	}
	if (r < size && array[r] > array[largest]) {
		largest = r;
	}
	if (i != largest) {
		Swap(&array[largest], &array[i]);
		Heapify(array, size, largest);
	}
}

void HeapSort(int* array, int size){
	for (int i = size / 2 - 1; i >= 0; --i) {
		Heapify(array, size, i);
	}
	for (int i = size-1; i > 0; --i) {
		Swap(&array[i], &array[0]);
		Heapify(array, i, 0);
	}
}

void Print(int array[],int size){
	for (int i = 0; i < size; ++i){
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int array[]={2,3,4,5,1};
	Print(array,5);
	HeapSort(array,5);
	Print(array,5);

	return 0;
}
