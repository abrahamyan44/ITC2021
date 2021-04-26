#include <iostream>
using namespace std;

template <class T>
void Swap(T* a, T* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


template <class T>
void BubbleSort(T arr[], int size)
{
	for (int i = 0; i < size; i++) {
		bool Swapped = false;

		for (int j = 1; j < size; j++) {
			if (arr[j] < arr[j-1]) {
				Swap( &arr[j], &arr[j-1]);
				Swapped = true;
			}

			if(Swapped == false) {
				break;
			}
		}
	}
}

template <class T>
int InterpolationSort(T arr[],int low, int high, T element) 
{
	if (arr[low] == element) {
		return low;
	}
	if(arr[high] == element) {
		return high;
	}
	
	int index = (element-arr[low])*(high - low)/(arr[high] - arr[low]);

	if(arr[index] == element) {
		return index;
	}
	if(element > arr[index]) {
		return InterpolationSort(arr, index + 1, high, element);
	}
	if(element < arr[index]) {
		return InterpolationSort(arr, low, index-1, element);
	}
	return -1;
}


int main()
{
	int size = 5;
	int element = 0;
	int arr[size]{};
	cout << "Enter 5 elements of arrey" << endl;
	
	for(int i = 0; i < size; i++) {
		cin >>arr[i];
	}
	BubbleSort(arr, size);

	for (int i = 0; i < size; i++){
		cout << arr[i] << "\t";
	}

	cout << "Which element did you need?" << endl;
	cin >> element;

	cout << "arr[ " << InterpolationSort(arr, 0, size, element) << " ]";
	cout << endl;
}
