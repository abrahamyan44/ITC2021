#include "SortingAlgorithms.hpp"
#include <map>
#include <ctime>
#include "Timer.hpp"
typedef long long ll;

using namespace std;

template <class T>
void RunAllAlgorithms(T* array, int size) {
    Timer<T> t(3);
    t.Run(QuickSort, size, array, "Quick");
	t.Run(BubbleSort, size, array, "Bubble");
	t.Run(MergeSort, size, array, "Merge");
	t.Run(HeapSort, size, array, "Heap");
	t.Run(InsertionSort, size, array, "Insertion");
	t.Run(SelectionSort, size, array, "Selection");
	t.Run(ShellSort, size, array, "Shell");
    t.Print();
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
