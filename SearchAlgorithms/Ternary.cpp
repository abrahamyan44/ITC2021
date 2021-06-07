#include <iostream>
using namespace std;

template <class T>
int search(T arr[], int low, int high, T element) {
	if(low <= high) {
		int middle_index1 = low + ((low + high) / 3);
		int middle_index2 =  high - ((low + high) / 3);
		if(arr[middle_index1] == element) {
			return middle_index1;
		}
		if(arr[middle_index2] == element) {
			return middle_index2;
		}
		if(arr[middle_index1] > element) {
			return	search(arr, low, middle_index1 - 1, element);
		}
		if(arr[middle_index2] <  element) {
			return	search(arr, middle_index2 + 1, high, element);
		}
		if(arr[middle_index2] > element) {
			return	search(arr, middle_index1 + 1, middle_index2 - 1, element);
		}
	}
	return -1;
}


template <class T>
void Swap (T* a, T* b) 
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void BubbleSort(T arr[], int size) 
{
	for (T i = 0; i < size; i++) {
		bool swapped = false;

		for (T j = 1; j < size - i; j++ ) {
				if (arr[j] < arr[j-1]) {
				Swap(&arr[j], &arr[j-1]);
				swapped = true;
			}
		}

		if (swapped == false) {
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
	int x = search(arr, 0, size - 1, element);

	cout<< "arr[ " << x << " ] = " << element << endl;
}

