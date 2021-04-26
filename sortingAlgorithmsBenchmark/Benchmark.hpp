#include <chrono> //for chrono, system_clock, duration 
#include <iomanip> // for setprecicion, setw

#include "Sortings.hpp"

using namespace std;
using namespace chrono;
using namespace Sortings;

bool Verification(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i) {
		if (array[i] > array[i + 1]) {
			return false;
		}
	}
	return true;
}

void PrintMinMaxAverage(double array_time[], int tests_count)
{
	double min = array_time[0], max = array_time[0], average = 0;

	for (int i = 0; i < tests_count; ++i) {
		average += array_time[i];
			
		if (min > array_time[i]) {
			min = array_time[i];
		}
		
		if (max < array_time[i]) {
			max = array_time[i];
		}
	}
	
	std::cout << "| Min |" << std::fixed << 
	std::setw(4) << std::setprecision(5) << min << "s " ; 

	std::cout << "| Avg |" << std::fixed << 
	std::setw(4) << std::setprecision(5) << average / tests_count << "s " ;

	std::cout << "| Max |" <<  std::fixed << 
	std::setw(4) << std::setprecision(5) << max << "s " ;
}


int* RandomArrayGenerator(int size)
{
	int* array = new int[size];

	for (int i = 0; i < size; ++i) {
		//array[i] = rand() % 100; 		   // Generate number between 0 to 99
		//array[i] = rand() % 2000 + 9000; // Generate number between 9000 to 11000 
		  array[i] = rand() % (20000 - 1) + (90000 + 1); // Generate number between 90001 to 110000 
	}

	return array;
}

int* CopyArray(int* arr, int size)
{
	int* newarr = new int [size];

	for (int i = 0; i < size; ++i) {
		newarr[i] = arr[i];
	}

	return newarr;
}

void Testing1(int* array, int size, void (*function_name)(int*, int), int tests_count)
{
	int* temp_array = CopyArray(array, size);	
	time_point<system_clock> start_time{}, end_time{};
	double array_time[tests_count] = {};

	for (int i = 1; i <= tests_count; ++i) {
		array = temp_array;	

		start_time = system_clock::now(); 		
		function_name(array,size);		
		end_time = system_clock::now();		
			
		if (!Verification(array, size)) {
			std::cout << "Error: Array is not sorted.";
			return;
		}

		duration<double> duration_time = (end_time - start_time);
		array_time[i - 1] = duration_time.count();
		
		if (1 == tests_count) {
			cout << std::fixed << std::setw(4) << std::setprecision(5)
				 << duration_time.count() << "s" << "      ";
		}
	}		
	if (1 < tests_count) {							
		PrintMinMaxAverage(array_time, tests_count);		
	}
	cout << endl;
	delete[] temp_array;
}

void Testing2(int* array, int start, int end, void (*function_name)(int*, int, int), int tests_count)
{
	int* temp_array = CopyArray(array, end + 1);	
	time_point<system_clock> start_time{}, end_time{};
	double array_time[tests_count] = {};

	for (int i = 1; i <= tests_count; ++i) {	
		array = temp_array;	

		start_time = system_clock::now(); 		
		function_name(array, start, end);
		end_time = system_clock::now();			

		if (!Verification(array, end + 1)) {
			std::cout << "Error: Array is not sorted.";
			return;
		}
		duration<double> duration_time = end_time - start_time;
		array_time[i - 1] = duration_time.count();
		
		if (1 == tests_count) {
			cout << std::fixed << std::setw(4) << std::setprecision(5) <<
			duration_time.count() << "s" << "      ";
		}
	}		
	if (1 < tests_count) {							
		PrintMinMaxAverage(array_time, tests_count);		
	}
	cout << endl;
}


