#include "sorting_benchmark.hpp"

template <class T>
T* CreateArray(int array_size) {		
	T* arr = new T[array_size];
	assert(nullptr != arr);
	srand (time(NULL));
	for(int i = 0; i < array_size; i++) {
		arr[i] = rand() % 1000;
	}
	
	cout << endl;
	return arr;
}

template <class T>
T* CopyArray(T* arr, int array_size) {
	T* arr2 = new T[array_size];
	assert(nullptr != arr2);
	for(int i = 0; i < array_size; i++) {
		arr2[i] = arr[i];
	}
	
	return arr2;
}

		
template <class T>
double* TestMetod1(T arr[], int array_size, double* result, int serial_number, int test_number, void (*function)(T*, int, int)) {
	for (int i = 0; i < test_number; i++) {
		T* copy_array = CopyArray(arr, array_size);	
		time_t begin;
		time_t end;
		time(&begin);
		function(arr, 0, array_size);
		time(&end);
		if(false == Verification(arr, array_size)) {
			exit;
		} 
		
		result[i + serial_number] =  difftime(end, begin); 
		delete[] copy_array;
		copy_array = nullptr;
		assert(nullptr == copy_array);
	}
	
	return result;
}

template <class T>
double* TestMetod(T arr[], int array_size, double* result, int serial_number, int test_number, void (*function)(T*, int)) {
	for (int i = 0; i < test_number; i++) {
		T* copy_array = CopyArray(arr, array_size);
		clock_t begin = clock();
		function(arr, array_size);
		clock_t end = clock();
		if(false == Verification(arr, array_size)) {
			exit;
		} 
		result[i + serial_number] = double(end - begin) / CLOCKS_PER_SEC;
		delete[] copy_array;
		copy_array = nullptr;
		assert(nullptr == copy_array);
	}
	
	return result;
}


double* CompareMethod(double* result, int test_number) { 
	double min;
	double max;

	for(int i = 0; i < 30; i += 6) {
		if(test_number > 1) {
			min = result[i];
			max = result[i + 1];
			if (result[i] > result[i + 1]) {
				max = result[i];
				min = result[i + 1];
			}
			if(test_number == 3) {
				if(max < result[i + 2]) {
					max = result[i + 2];
				}
				if(min > result [i + 2]) {
					min = result[i + 2];
				}
			} 
		} else if(1 == test_number) {
			min = result[i];
			max = result[i];
		}
		result[i + 3] = min;
		result[i + 4] = max;
		if (3 == test_number) {
			result[i + 5] = (result[i] + result[i + 1] + result[i + 2]) / 3; 
		} else if (2 == test_number) {
			result[i + 5] = (result[i] + result[i + 1]) / 2; 
		} else if (1 == test_number){
			result[i + 5] = result[i];
		}
	}
	return result;
}

template <class T>
double* Test(T arr[], int array_size, int test_number) {
	double* result = new double[30];
	assert(nullptr != result);
	result = TestMetod(arr, array_size, result, 0, test_number, BubbleSort);
	result = TestMetod(arr, array_size, result, 6, test_number, SortHeap);
	result = TestMetod(arr, array_size, result, 12, test_number, ShellSort);
	result = TestMetod1(arr, array_size, result, 18, test_number, QuickSort);
	result = TestMetod1(arr, array_size, result, 24, test_number, MergeSort);
	result = CompareMethod(result, test_number);

	return result;
}

void PrintMetod(string sort_name, double* result, int test_number, int serial_number) {
	cout << sort_name << "\t";
	for(int i = 0; i < 3; i++) {
		cout << setprecision(4) << fixed;
		cout << result[i + serial_number + 3] << " \t \t";
	}
	
	cout << endl;
}

template <class T>
void Print(T* result, int test_number) {
	cout << "Sorting type \t";	
	cout << "Minimum \t" << "Maximum \t" << "Average result" << endl;
   
 	PrintMetod("BubbleSort", result, test_number, 0);
   	PrintMetod("SortHeap", result, test_number, 6);
   	PrintMetod("ShellSort", result, test_number, 12);
   	PrintMetod("QuickSort", result, test_number, 18);
   	PrintMetod("MergeSort", result, test_number, 24);
}

int main (int argc, char** argv) {
	int* array;
	double* result;
	int array_size = atoi(argv[1]);
	int test_number = atoi(argv[2]);
	array = CreateArray<int>(array_size);
	result = Test<int>(array, array_size, test_number);
	Test(array, array_size, test_number);
	Print<double>(result, test_number);
}
