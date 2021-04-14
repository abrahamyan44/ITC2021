#include <iostream>
using namespace std;

template <class T>
void Swap (T* a, T* b)
{
int tamp = *a;
*a = *b;
*b = tamp;
}

template <class T>
void SelectionSort(T arr[], int size)
{
	for(int i = 0; i < size; i++) {
		int min_index = i;
		bool FindMinimum = false;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		Swap(&arr[i], &arr[min_index]);
	}
}

template <class T>
void print(T arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t" ;
	}
	cout << endl;
}


template <class T>
void test ()
{
	size_t size = 7;
	T arr1[]{4, 18, 16, 3, 25, 64, 32};
	T arr2[]{1167, 6789, 5643, 9087, 2345, 7689, 5634};
	T arr3[]{ 87, 0, -98, -45, 76, 45, -10};

	T expected_result1[]{3, 4, 16, 18, 25, 32, 64};
	T expected_result2[]{1167, 2345, 5634, 5643, 6789, 7689, 9087};
	T expected_result3[]{-98, -45, -10, 0, 45, 76, 87};

	SelectionSort(arr1, size);
	SelectionSort(arr2, size);
	SelectionSort(arr3, size);

	for(int i = 0; i < size; i++) {
		if (arr1[i] == expected_result1[i]) {
			cout << "test1 ok \t ";
		}
		
		if (arr2[i] == expected_result2[i]) {
			cout << "test2 ok \t";
		}

		if (arr3[i] == expected_result3[i]) {
			cout << "test3 ok \t";
		}
		cout << endl;
	}
}



int main() 
{
	int size = 5;
	int arr[size]{};
	test<int>();
	cout<< "Enter 5 integers, please"<< endl;
	
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	print<int>(arr, size);

	SelectionSort<int>(arr, size);

	print<int>(arr, size);
}
