#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <class T>
void Swap(T* a, T* b) 
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void BubbleSort(T arr[], int array_size)
{
	for(int i = 0; i < array_size; i++) {
			bool swapped = false;
		for(int j = 1; j < array_size - i; j++) {
			if(arr[j] < arr[j-1]) {
				Swap(&arr[j], &arr[j-1]);
				swapped = true;
			}
		}
		if (swapped == false) {
				break;
		}
	}
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
T* CreateArray(int array_size)
{		
	T* arr = new T[array_size];
	srand (time(NULL));
	for(int i = 0; i < array_size; i++) {
		arr[i] = rand()%1000;
	
	}
	cout << endl;
	return arr;
}

template <class T>
T* CopyArray(T* arr, int array_size)
{
	T* arr2 = new T[array_size];
	for(int i = 0; i < array_size; i++) {
		arr2[i] = arr[i];
	}
	return arr2;
}

template <class T>
T* TestMetod (T arr[], int array_size, T* result, int serial_number, int test_number, void (*function)(T*, int)) 
{
	for (int i = 0; i < test_number; i++) {
	T* copy_array = CopyArray(arr, array_size);
	time_t begin;
	time_t end;
	time(&begin);
	function(arr, array_size);
	time(&end);
	result[i + serial_number] = difftime(end, begin);
	delete[] copy_array;
	}
	return result;
}

template <class T>
T* CompareMethod (T* result, int serial_number, int test_number) 
{
	T min;
	T max;
	if (1 == test_number) {
		for (int i = 0; i < 25; i+=5) {
			result[i+3] = result[i + 4] =result[i];
			break;

	}
		for(int i = 0; i < 25; i+=5) {
		min = result[i];
		max = result[i + 1];
		if (result[i] > result[i + 1]) {
			Swap(&min, &max);
		}
		if( max < result[i+2]) {
			max = result[i +2];
		}
		if(min > result [i+2]) {
			min = result[i+2];
		}
		result[i+3] = min;
		result[i+4] = max;
		}
		}
	return result;
}

template <class T>
T* test (T arr[], int array_size, int test_number)
{
	T* result = new T[25];
	result = TestMetod(arr, array_size, result, 0, test_number, BubbleSort);
	result = TestMetod(arr, array_size, result, 5, test_number, SelectionSort);

	return result;
}

template <class T>
void PrintMetod(string sort_name, T* result, int test_number, int serial_number)
{
	cout << sort_name << "\t";
	for(int i = 0; i < test_number; i++ ) {
		cout << result[i + serial_number] << "\t \t";
	}
	cout << endl;
}

template <class T>
void Print(T* result, int test_number)
{
	cout << "Sorting type \t";
   for(int i = 0; i < test_number; i++) {
 		cout << "Test N " << i + 1 << "\t";
   }	
   cout << "Minimum \t" << "Maximum \t" << "Average result" << endl;
   
   PrintMetod("BubbleSort", result, test_number, 0);
   PrintMetod("SelectionSort", result, test_number, 5);
}

int main (int argc, char** argv)
{
	int* array;
	double* result;
	int array_size = atoi(argv[1]);
	int test_number = atoi(argv[2]);

	array = CreateArray<int>(array_size);
	result = TestMetod<double>(array, array_size, test_number);

	Print<double>(result, test_number);
/*	for (int i = 0; i < 6; i++)
	{
		cout << result[i] << "\t";
	} */
}
