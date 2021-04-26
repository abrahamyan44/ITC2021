#include <iostream>
using namespace std;

template <class T>
void Swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}	

template <class T>
void Heapify(T arr[], int size, int i)
{ 
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if(left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	if(right < size && arr[right] > arr[largest]) {
		largest = right;
	}
	if(largest != i) {
		Swap(&arr[largest], &arr[i]);
		Heapify(arr, size, largest);
	}
}

template <class T>
void SortHeap(T arr[], int size)
{
	for(int i = size / 2 - 1; i >= 0; i--) {
		Heapify(arr, size, i);	
	}
	for(int i = size - 1; i > 0; i--) {
		Swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);
	}
}

template <class T>
void Print(T arr[], int size)
{
	for(int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main() 
{	
	int size;
	cout << "How many elements do you want to insert?" << endl;
	cin >> size;
	cout << "Enter the numbers for array" << endl;
        int arr[size]{};

	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	SortHeap(arr, size);
	Print(arr, size);

	return 0;
}
