#include "sorting_benchmark.hpp"
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
double* TestMetod(T arr[], int array_size, double* result, int serial_number, int test_number, void (*function)(T*, int)) 
{
	for (int i = 0; i < test_number; i++) {
		T* copy_array = CopyArray(arr, array_size);
	
		clock_t begin = clock();
		function(arr, array_size);
		clock_t end = clock();
		if(false == verification(arr, array_size)) {
			exit;
		}
		result[i + serial_number] = double(end - begin) / CLOCKS_PER_SEC;
		delete[] copy_array;
	}

	return result;
}


double* CompareMethod(double* result, int test_number) 
{ 
	double min;
	double max;
	if (1 == test_number) {
		for (int i = 0; i < 30; i += 6) {
			result [i+3] = result[i+4] = result [i];
		} 
	}
		for(int i = 0; i < 30; i += 6) {
			min = result[i];
			max = result[i + 1];
			if (result[i] > result[i + 1]) {
				Swap(&min, &max);
			}
			if(max < result[i + 2]) {
				max = result[i + 2];
			}
			if(min > result [i + 2]) {
				min = result[i + 2];
			}
			result[i + 3] = min;
			result[i + 4] = max;
			result[i + 5] = (result[i] + result[i + 1] + result[i + 2]) / 3;
			}
	return result;

}


template <class T>
double* Test(T arr[], int array_size, int test_number)
{
	double* result = new double[30];
	result = TestMetod(arr, array_size, result, 0, test_number, BubbleSort);
	result = TestMetod(arr, array_size, result, 6, test_number, SelectionSort);
	result = CompareMethod(result, test_number);

	return result;
}

void PrintMetod(string sort_name, double* result, int test_number, int serial_number)
{
	cout << sort_name << "\t";
	for(int i = 0; i < test_number + 3; i++) {
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
   PrintMetod("SelectionSort", result, test_number, 6);
}

int main (int argc, char** argv)
{
	int* array;
	double* result;
	int array_size = atoi(argv[1]);
	int test_number = atoi(argv[2]);

	array = CreateArray<int>(array_size);
	result = Test<int>(array, array_size, test_number);

	Print<double>(result, test_number);
}
