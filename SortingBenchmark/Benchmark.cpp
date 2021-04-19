#include <iostream>
#include <cstring>
#include <iomanip>
#include <time.h>
#include <chrono>

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
bool isSorted(T* array, int size)
{
    int i;
    for (i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

int GetAverage(int* vector, int size)
{
    int average_value = 0;
    for (int i = 0; i < size; ++i) {
        average_value += vector[i];
    }
    return (average_value / size);
}

int GetMaximum(int* vector, int size)
{
    int max = vector[0];
    for (int i = 1; i < size; ++i) {
        if (max <= vector[i]) {
            max = vector[i];
        }
    }
    return max;
}

int GetMinimum(int* vector, int size)
{
    int min = vector[0];
    for (int i = 0; i < size; ++i) {
        if (min >= vector[i]) {
            min = vector[i];
        }
    }
    return min;
}

template <typename T>
void TestTheAlgorithm(void (*AlgorithmName)(T*, int),T* array, int size_array, int test_count = 1)
{
    T array_copy[size_array];
    int test_result[test_count];
    for (int i = 1; i <= test_count; ++i) {
        CopyArray(array,array_copy, size_array);
        auto start = std::chrono::high_resolution_clock::now();
        AlgorithmName(array_copy, size_array);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        test_result[i - 1] = duration.count();
    }
    if (isSorted(array_copy, size_array)) {
        std::cout << "Array is sorted.\n";
    } else {
        std::cout << "Array is not sorted.\n";
    }
    std::cout << "\tMaximum time is equal " << GetMaximum(test_result, test_count) << " milliseconds.\n";
    std::cout << "\tMinimum time is equal " << GetMinimum(test_result, test_count) << " milliseconds.\n";
    std::cout << "\tAverage time is equal " << GetAverage(test_result, test_count) << " milliseconds.\n";
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "Wrong argumnets quantity.\n";
        return 0;
    }
    if (!isNumber(argv[1]) || !isNumber(argv[2])) {
        std::cout << "Passed wrong arguments\n";
        return 0;
    }
    const int count_element = atoi(argv[1]);
    int count_tests = atoi(argv[2]);
    if (count_tests < 1 || count_tests > 3) {
        std::cout << "Wrong testing quantity.\n";
        return 0;
    }
    int64_t array[count_element];
    GenerateVector(array, count_element, 2 * count_element);
    
    std::cout << "Tests a Quick sort algorithm.\n";
    TestTheAlgorithm(&QuickSort, array, count_element ,count_tests);
   
    std::cout << "\nTests a Shell sort algorithm.\n";
    TestTheAlgorithm(&ShellSort, array, count_element, count_tests);
 
    std::cout << "\nTests a Merge sort algorithm.\n";
    TestTheAlgorithm(&MergeSort, array, count_element, count_tests);

    std::cout << "\nTests a Heap sort algorithm.\n";
    TestTheAlgorithm(&HeapSort, array, count_element, count_tests);

    std::cout << "\nTests a Selection sort algorithm.\n";
    TestTheAlgorithm(&SelectionSort, array, count_element, count_tests);

    std::cout << "\nTests a Insertion sort algorithm.\n";
    TestTheAlgorithm(&InsertionSort, array, count_element, count_tests);
}

