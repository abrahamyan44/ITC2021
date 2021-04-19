#include "SortingAlgorithms.h"
#include "RunAlgorithms.h"
typedef long long ll;

template <class T>
void RunAllAlgorithms(T* array, int size) {
    RunBubbleSort(array, size);
    RunQuickSort(array, size);
    RunSelectionSort(array, size);
    RunInsertionSort(array, size);
    RunShellSort(array, size);
    RunHeapSort(array, size);
    RunMergeSort(array, size);
}

template <class T>
T*  GenerateRandomArray(int size) {
    T* array = new T[size];
	for (int i = 0; i < size; ++i) {
		array[i] = rand();
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
