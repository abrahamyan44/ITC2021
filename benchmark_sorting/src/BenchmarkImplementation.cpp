#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include "SortingAlgorithms.h"
#include "Timer.h"
typedef long long ll;

using namespace std;

template <class T>
extern void QuickSort(int, T*);
template <class T>
extern void BubbleSort(int, T*);
template <class T>
extern void InsertionSort(int, T*);
template <class T>
extern void SelectionSort(int, T*);
template <class T>
extern void ShellSort(int, T*);
template <class T>
extern void HeapSort(int, T*);
template <class T>
extern void MergeSort(int, T*);

template <class T>
void RunAllAlgorithms(T* array, int size) {
    Timer<T> t(3);
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

template <class T>
T*  GenerateRandomArray(int size) {
    T* array = new T[size];
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 81;
	}
    return array;
}

template <class T>
void CreateArray(int size) {
    T* array = GenerateRandomArray<T>(size);
    RunAllAlgorithms(array, size);
}

int main(int argc, char** argv) {
	srand(time(0));
	int size = atoi(argv[1]);
//	int size = 100;
    char type;
    if (argc < 3) {
        type = 'i';
    } else {
	    type = argv[2][0];
    }
	if (type == 'c') {
		CreateArray<char>(size);
	} else if (type == 'l') {
		CreateArray<ll>(size);
	} else if (type == 'd') {
		CreateArray<double>(size);
	} else {
        CreateArray<int>(size);
	}
	return 0;
}
