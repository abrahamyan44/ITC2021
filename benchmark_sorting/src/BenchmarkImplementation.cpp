#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include "../include/BenchmarkTable.hpp"
#include "../include/Timer.hpp"

typedef long long ll;

using namespace std;

extern void QuickSortByBagratid(int, int*);

extern void BubbleSortByBagratid(int, int*);

extern void SelectionSortByBagratid(int, int*);

extern void InsertionSortByBagratid(int, int*);

extern void ShellSortByBagratid(int, int*);

extern void HeapSortByBagratid(int, int*);

extern void MergeSortByBagratid(int, int*);


void RunAllBagratidAlgorithms(int* array, int size) {
    BenchmarkTable table(3);
	try {
		table.Run(BubbleSortByBagratid, size, array, "Bubble");
		table.Run(QuickSortByBagratid, size, array, "Quick");
		table.Run(MergeSortByBagratid, size, array, "Merge");
		table.Run(HeapSortByBagratid, size, array, "Heap");
		table.Run(InsertionSortByBagratid, size, array, "Insertion");
		table.Run(SelectionSortByBagratid, size, array, "Selection");
		table.Run(ShellSortByBagratid, size, array, "Shell");
	} catch(const string s) {
		cout << s << endl;
		return;
	}
    table.PrintTable();
}


int*  GenerateRandomArray(int size) {
    int* array = new int[size];
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 81;
	}
    return array;
}

int main(int argc, char** argv) {
	srand(time(0));
	int size = atoi(argv[1]);
    int* array = GenerateRandomArray(size);
    RunAllBagratidAlgorithms(array, size);
	return 0;
}
