#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include "BenchmarkTable.hpp"
#include "Timer.hpp"
#include "SortingAlgorithms.hpp"
typedef long long ll;

using namespace std;

// extern template ByBagratid;

template <class T, class T1>
void RunAllAlgorithms(T* array, int size) {
    BenchmarkTable t(3);
	try {
		cout << typeid(T1).name() << endl;
		t.Run(T1::BubbleSort, size, array, "Bubble");
		t.Run(T1::QuickSort, size, array, "Quick");
		t.Run(T1::MergeSort, size, array, "Merge");
		t.Run(T1::HeapSort, size, array, "Heap");
		t.Run(T1::InsertionSort, size, array, "Insertion");
		t.Run(T1::SelectionSort, size, array, "Selection");
		t.Run(T1::ShellSort, size, array, "Shell");
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
    RunAllAlgorithms<T, ByBagratid>(array, size);
}

int main(int argc, char** argv) {
	srand(time(0));
	int size = atoi(argv[1]);
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
