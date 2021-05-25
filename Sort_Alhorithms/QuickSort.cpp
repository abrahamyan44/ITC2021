#include <iostream>
using namespace std;

template <class T>
void Swap (T* a, T* b) 
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
int partitioning(T arr[], int low, int high)  
{
	int i = (low-1);
	int pivot = arr[high];
	
	for(int j = low; j < high; j++) {
		if(arr[j] <= pivot) {
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}

	Swap(&arr[i+1], &arr[high]);
	return (i+1);
}	

template <class T>
void QuickSort(T arr[], int low, int high)
{ 
	if (low < high){
		int separate = partitioning(arr, low, high);
		QuickSort(arr, separate + 1, high);
		QuickSort(arr, low, separate - 1);
	}
}

template <class T>
void print(T arr[], int size) 
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] <<"\t"; 
	}
	cout << endl;
}


template <class T>
void test ()
{
	int size = 7;
	T arr1[]{4, 18, 16, 3, 25, 64, 32};
	T arr2[]{1167, 6789, 5643, 9087, 2345, 7689, 5634};
	T arr3[]{ 87, 0, -98, -45, 76, 45, -10};

	T expected_result1[]{3, 4, 16, 18, 25, 32, 64};
	T expected_result2[]{1167, 2345, 5634, 5643, 6789, 7689, 9087};
	T expected_result3[]{-98, -45, -10, 0, 45, 76, 87};
	cout << endl;

	QuickSort(arr1, 0, size - 1);
	QuickSort(arr2, 0, size - 1);
	QuickSort(arr3, 0, size - 1);

	for(int i = 0; i < size; i++) {
		if (arr1[i] == expected_result1[i]) {
			cout << "test1 ok \t ";
		}else {
			cout << "test1 failed \t";
		}
		
		if (arr2[i] == expected_result2[i]) {
			cout << "test2 ok \t";
		} else {
			cout << "test1 failed \t";
		}

		if (arr3[i] == expected_result3[i]) {
			cout << "test3 ok \t";
		} else {
			cout << "test1 failed \t";
		}
		cout << endl;
	}
	cout << endl;
}


int main() 
{
	int size = 5;
	int arr[size]{};
	
	test<int>();	
	cout  << "Please, enter 5 integers." << endl;

	for (int i = 0; i < size; i++) {
		cin >> arr[i]; 
	}

	print<int>(arr, size);
	QuickSort<int>(arr, 0, size - 1);
	print<int>(arr, size);
}
