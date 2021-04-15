#include <iostream>
using namespace std;

int search(int arr[], int low, int high, int element) {
	if(low <= high) {
		int middle_index = (low + high) / 2;
		if(arr[middle_index] == element) {
			return middle_index;
		}
	       	if(arr[middle_index] > element) {
			return	search(arr, low, middle_index - 1, element);
		}
		if(arr[middle_index] < element) {
			return search(arr, middle_index + 1, high, element);
		}		
	}
	return -1;
}


void Swap(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int arr[], int size) 
{
	for (int i = 0; i < size; i++) {
		bool swapped = false;
		for(int j = 1; j < size - i; j++) {
			if(arr[j] < arr[j-1]) {
				Swap(&arr[j], &arr[j-1]);
				swapped = true;
			}
		}
		if(swapped == false) {
			break;
		}
	}
}

int main() 
{
	cout << "Enter 5 integers." << endl;
	int size = 5;
	int element;
	int arr[size]{};

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	BubbleSort(arr, size);
	cout << "Sorted array" << endl;
	for(int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}

	cout << endl;
	cout << "which element's number did you need?" << endl;
	cin >> element;

	cout<< "arr[ " << search(arr, 0, size - 1, element)  << " ] = " << element << endl;
}

