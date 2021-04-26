#include <iostream>
using namespace std;

template <class T>
void Shell(T* array, int size)
{
	for(int interval = size/2; interval > 0; interval /= 2) {
		for(int i = interval; i < size; i++) {
			T temp = array[i];
			int j;
			for(j = i; j >= interval && array[j-interval] > temp; j -= interval) {
				array[j] = array[j-interval];
			}
			array[j] = temp;
		}
	}
}

template <class T>
void print(T* array, int size)
{
	for(int i = 0; i < size; i++) {
		cout << array[i] << "\t";
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
	Shell(arr1, size);
	Shell(arr2, size);
	Shell(arr3, size);
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
	test<int>();
	int array[10]{};
	for(int i = 0; i < 10; i++) {
		array[i] = rand()%30;
	}
	print(array, 10);
	Shell(array,10);
	print(array, 10);
}
