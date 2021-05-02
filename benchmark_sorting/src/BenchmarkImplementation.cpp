#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include "../include/BenchmarkTable.hpp"
#include "../include/Timer.hpp"
//#include "SortingAlgorithms.cpp"
//#include "Timer.cpp"
//#include "BenchmarkTable.cpp"

typedef long long ll;

using namespace std;

extern void QuickSort(int, int*);

extern void BubbleSort(int, int*);

extern void SelectionSort(int, int*);

extern void InsertionSort(int, int*);

extern void ShellSort(int, int*);

extern void HeapSort(int, int*);

extern void MergeSort(int, int*);


void RunAllAlgorithms(int* array, int size) {
    BenchmarkTable t(3);
	try {
		t.Run(BubbleSort, size, array, "Bubble");
		t.Run(QuickSort, size, array, "Quick");
		t.Run(MergeSort, size, array, "Merge");
		t.Run(HeapSort, size, array, "Heap");
		t.Run(InsertionSort, size, array, "Insertion");
		t.Run(SelectionSort, size, array, "Selection");
		t.Run(ShellSort, size, array, "Shell");
	} catch(const string s) {
		cout << s << endl;
		return;
	}
    t.PrintTable();
}


int*  GenerateRandomArray(int size) {
    int* array = new int[size];
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 81;
	}
    return array;
}


void CreateArray(int size) {
    int* array = GenerateRandomArray(size);
    RunAllAlgorithms(array, size);
}

int main(int argc, char** argv) {
	srand(time(0));
	int size = atoi(argv[1]);
	CreateArray(size);
	return 0;
}
