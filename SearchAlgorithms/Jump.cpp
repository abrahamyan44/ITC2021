#include <iostream>
#include <cmath>
using namespace std;


int JumpSearch(int arr[], int size, int element) {
	for (int i = 0; i < size; i = i + sqrt(size)) {
		if (arr[i] == element) {
			return i;
		}
		if (arr[i] > element) {
			for (int j = i; j > i - sqrt(size); --j) {
        	        	if (arr[j] == element) {
	        	                return j;
	                         	break;
                		}
        		}
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
	cout << "arr [ " << JumpSearch(numbersArray, size, element) << " ]" << endl; 


	return 0;
}
