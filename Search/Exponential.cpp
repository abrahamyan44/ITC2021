#include <iostream>
using namespace std;

int BinarySearch(int  arr[], int low, int high, int element) {
	if (low <= high) {
		int middle_index = ( low + high) / 2;
		if (arr[middle_index] == element) {
			return middle_index;
		}
	       	if(arr[middle_index] > element) {
			return	BinarySearch(arr, low, middle_index - 1, element);
		}
		if(arr[middle_index] < element) {
			return BinarySearch(arr, middle_index + 1, high, element);
		}		
	}
	return -1;
}



int ExponentialSearch(int arr[], int size, int element) {
	if (arr[0] == element) {
		return 0;
	}
	for (int i = 1; i < size; i *= 2) {
		if (arr[i] == element) {
			return i;
		}
		if (arr[i] > element) {		
			return BinarySearch(arr, i / 2, i, element);
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



int main() {
	int size = 5;
	int numbersArray[size]{};
	int element = 0;
	cout << "Enter 5 numbers" << endl;
	for (int i = 0; i < size; ++i) {
		cin >> numbersArray[i];
	}
	cout << endl;
	BubbleSort(numbersArray, size);
	cout << "Sorted array" << endl;
	for(int i = 0; i < size; i++) {
		cout << numbersArray[i] << "\t";
	}

	cout << endl;

	cout << "Enter number you want to search" << endl;
	cin >> element;

	cout << "arr [ " << ExponentialSearch(numbersArray, size, element) << " ]" << endl; 


	return 0;
}
