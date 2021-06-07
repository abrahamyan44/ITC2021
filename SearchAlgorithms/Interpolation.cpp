#include <iostream>
using namespace std;

template <class T>
int InterpolationSearch(T arr[], int low, int high, T element) {
	if (low <= high) {
		int index = low + ( ((element - arr[low]) / (arr[high] - arr[low])) * (high - low));
		if (arr[index] == element) {
			return index;
		}
	       	if(arr[index] > element) {
			return InterpolationSearch(arr, low, index - 1, element);
		}
		if(arr[index] < element) {
			return InterpolationSearch(arr, index + 1, high, element);
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
	int x = InterpolationSearch(arr, 0, size - 1, element);

	cout<< "arr[ " << x << " ] = " << element << endl;
}

