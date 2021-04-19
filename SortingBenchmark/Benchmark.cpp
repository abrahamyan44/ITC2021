#include <iostream>
#include <cstring>
#include <iomanip>
#include <time.h>
#include <chrono>
#include "Algotithms.cpp"


template <typename T>
void QuickSort (T*, int);

template <typename T>
void ShellSort (T*, int);

template <typename T>
void MergeSort (T*, int);

template <typename T>
void HeapSort (T*, int);

template <typename T>
void SelectionSort (T*, int);

template <typename T>
void InsertionSort (T*, int);

template <typename T>
void GenerateVector (T* array, int size, int interval = 50)
{
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        array[i] = rand()% interval - interval / 2;
    }
}

template <typename T>
void PrintVector (T* array, int size)
{ 
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << array[i];
        std::cout << ",";
    }
    std::cout << std::endl;
}

bool isNumber(const char* string) {
  const int string_len = strlen(string);
  for(int i = 0; i < string_len; ++i) {
    if(!isdigit(string[i]))
      return false;
  }
  return true;
}

template <typename T>
void CopyArray(T* old_array, T* new_array, int size)
{
    for (int i = 0; i < size; ++i) {
        new_array[i] = old_array[i];
    }
}

template <typename T>
void TestTheAlgorithm(void (*Algorithm_name)(T*, int),T* array, int size_array, int test_count = 1)
{
    T array_copy[size_array];
    if (test_count < 1 && test_count > 3) {
        std::cout << "Wrong testing count.\n";
        return;
    }
    for (int i = 1; i <= test_count; ++i) {
        CopyArray(array,array_copy, size_array);
        auto start = std::chrono::high_resolution_clock::now();
        Algorithm_name(array_copy, size_array);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "\tTEST " << i << ": Time is equal " << duration.count() << " milliseconds.\n";
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "Wrong argumnet count.\n";
        return 0;
    }
    if (!isNumber(argv[1]) && !isNumber(argv[2])) {
        std::cout << "Passed wrong arguments\n";
        return 0;
    }
    const int count_element = atoi(argv[1]);
    int count_tests = atoi(argv[2]);
    int64_t array[count_element];
    GenerateVector(array, count_element, 2 * count_element);
    
    std::cout << "Test Quick sort algorithm\n";
    TestTheAlgorithm(&QuickSort, array, count_element ,count_tests);
   
    std::cout << "Test Shell sort algorithm\n";
    TestTheAlgorithm(&ShellSort, array, count_element, count_tests);
 
    std::cout << "Test Merge sort algorithm\n";
    TestTheAlgorithm(&MergeSort, array, count_element, count_tests);

    std::cout << "Test Heap sort algorithm\n";
    TestTheAlgorithm(&HeapSort, array, count_element, count_tests);

    std::cout << "Test Selection sort algorithm\n";
    TestTheAlgorithm(&SelectionSort, array, count_element, count_tests);

    std::cout << "Test Insertion sort algorithm\n";
    TestTheAlgorithm(&InsertionSort, array, count_element, count_tests);
}
