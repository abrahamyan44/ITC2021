#include <iostream>

void InsertionSort(int array[], int size){
	int key, j;
	for(int i = 1; i < size; ++i){
		key = array[i];
		j = i - 1;
		while(j >= 0 && key < array[j]){
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void PrintArray(int array[], int size){
	for(int i = 0; i < size; ++i){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main(){
	int array[] = { 45, 23, 67, 1, 98 };
	int n = sizeof(array) / sizeof(array[0]);
	std::cout << "Array before sorting" << std::endl;
	PrintArray(array, n);
	InsertionSort(array, n);
	std::cout << "Array after insertion sorting" << std::endl;
	PrintArray(array, n);
	return 0;
}
