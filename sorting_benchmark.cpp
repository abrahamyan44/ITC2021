#include <iostream>
#include <ctime>
using namespace std;

template <class T>
void Swap(T* a, T* b) 
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void SelectionSort(T arr[], int array_size)
{
	for(int i = 0; i < array_size; i++)
	{	int min_index = i;
		for(int j = i + 1; j < array_size; j++) {
			if(arr[j] < arr[j - 1]) {
				min_index = j;
			}
		}
		Swap(&arr[i], &arr[min_index]);
	}
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
T* MakeCopy(T arr1[], int array_size) 
{
	T* arr2 = new int [array_size];
	for (int i = 0; i < array_size; i++) {
		arr2[i] = arr1[i];
	}
	return arr2;
}

template <class T>
int* Test(T arr[], int array_size, int test_number, void (*function)(T*,int))	
{
	int* test_result = new int [test_number];
	int* array1 = MakeCopy(arr, array_size);
	int* array2 = MakeCopy(arr, array_size);
	int* array3 = MakeCopy(arr, array_size);
	time_t begin1;
	time_t end1;
	time(&begin1);
	function(array1, array_size);
	time(&end1);
	double difference1 = difftime(end1, begin1);
	test_result[0] = difference1;
	if(test_number > 1) {
		time_t begin2;
		time_t end2;
		time(&begin2);
		function(array2, array_size);
		time(&end2);
		double difference2 = difftime(end2, begin2);
		test_result[1] = difference2;
	}
	
	if(test_number > 2) {
		time_t begin3;
		time_t end3;
		time(&begin3);
		function(array3, array_size);
		time(&end3);
		double difference3 = difftime(end3, begin3);
		test_result[ 2 ] = difference3;
	
	}
	delete[] array1;
	delete[] array2;
	delete[] array3;
	return test_result;
	delete test_result;
}

template <class T>
T* CreateArray(int array_size)
{
		
	int* arr = new int[array_size];
/*	int array_type;
	cout << "What type of arrey elements do you want? \n 1. integer \n 2. float \n 3. double \n 4. string "	<< endl;
	
	cin >> array_type ;
	switch (array_type) {
		case 1:
		int* arr = new int[array_size];
		
		case 2:
		float* arr = new int[array_size];

		case 3:
		double * arr = new int[array_size];

		case 4:
		string* arr = new int[array_size];
	} */
	srand (time(NULL));
	for(int i = 0; i < array_size; i++) {
		arr[i] = rand()%1000;
	
	}
//	for(int i = 0; i < array_size; i++) {
//		cout << arr[i] << "\t";
//	}
	cout << endl;
	return arr;
}

void Print(int arr[], int test_number)
{
	cout << "Sorting type \t";
	for(int i = 0; i < test_number; i++) {
		cout << "test N " << i << "\t" ;
	}
	cout << endl;
	cout << "BubbleSort \t";
	for(int i = 0; i < test_number; i++){
		cout << arr[ i + 1] << "\t \t";
	}
	cout << endl;
	cout << "SelectionSort \t";
	for(int i = 0; i < test_number; i++){
		cout << arr[ i + 3] << "\t \t";
	}
	cout << endl;
}


int main() 
{	
	int array_size;
	int test_number;
	int* array;
	int* test_result;
	int* result = new int [5 * test_number]; 
	int* preliminary_result;

	cout << "How many elements include in array? " << endl;	
	cin >> array_size;
	cout << "How many times to test? /min 1; max 3/" << endl;

	cin >> test_number;
	while (test_number != 1 && test_number != 2 && test_number != 3){
		cout << "Wrong choice \n" << "Enter agayn how many test to / min 1; max 3/" << endl;
		cin >> test_number;
	}

	array = CreateArray<int>(array_size);	
		
	test_result  = Test<int>(array, array_size, test_number, BubbleSort);
	for(int i = 0; i < test_number; i++){
		result[i] = test_result[i];
	}

	test_result  = Test<int>(array, array_size, test_number, SelectionSort);
	for(int i = 0; i < test_number; i++){
		result[i+3] = test_result[i];
	}


	Print(result, test_number);
	cout << endl;

}
