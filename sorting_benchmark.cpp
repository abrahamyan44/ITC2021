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
void BubbleSort(T arr[], int array_size)
{
		cout << "Bubble" << endl;
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
T* MakeCopy(T arr[]) 
{
	//return the copy of givrn array;
	return 0;
}

template <class T>
int* Test(T arr[], int array_size, int test_number)	
{
	int* test_result;
	time_t begin;
	time_t end;
 	cout << "test" << endl;	
	for( int i = 0; i < test_number; i++) {
		cout << "test for" << endl;
		time(&begin);
		BubbleSort(arr, array_size);
		time(&end);
	
		double difference = difftime(end, begin);
		cout << "time = " << difference;
		test_result[1 * i ] = difference;
	}
	cout << "for out" << endl;
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
		cout << "test N " << i << "\t" << endl;
	}
	cout << "BubbleSort \t";
	for(int i = 0; i < test_number; i++){
		cout << arr[1 * i] << "\t";
	}
	cout << endl;
}


int main() 
{	
	int array_size;
	int test_number;
	int* array;
	int* test_result;

	cout << "How many elements include in array? " << endl;	
	cin >> array_size;
	cout << "How many times to test? /min 1; max 3/" << endl;

	cin >> test_number;
	while (test_number != 1 && test_number != 2 && test_number != 3){
		cout << "Wrong choice \n" << "Enter agayn how many test to / min 1; max 3/" << endl;
		cin >> test_number;
	}

	array = CreateArray<int>(array_size);	

//	Test<int>(array, array_size, test_number);
	test_result = Test<int>(array, array_size, test_number);
	Print(test_result, test_number);
	cout << endl;

}
