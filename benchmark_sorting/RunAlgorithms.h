#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

void Print(string name, double* work_time) {
    sort(work_time, work_time + 3);
    cout << name << " sort is working correctly!" << endl;
    cout << "Minimum time for " << name << " sort is: " << work_time[0] << endl;
    cout << "Average time for " << name << " sort is: " << (work_time[0] + work_time[1] + work_time[2]) / 3 << endl;
    cout << "Maximum time for " << name << " sort is: " << work_time[2] << endl;
    cout << endl;
}

template <class T>
T* CopyArray(int size, T* array) {
    T* new_array = new T[size];
    for (int i = 0; i < size; ++i) {
        new_array[i] = array[i];
    }
    return new_array;
}

template <class T>
bool CheckingIfSortedCorrectly(int size, T* array) {
    for (int i = 1; i < size; ++i) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

template <class T>
void RunBubbleSort(T* array, int size) {
    double work_time[3];
    for (int i = 0; i < 3; ++i) {
        T* new_array = CopyArray(size, array);
        clock_t start_time = clock();
        SortingArrayWithBubbleSort(size, new_array);
        if (i == 0 && !CheckingIfSortedCorrectly(size, new_array)) {
            cout << "Bubble Sort doesn't work correctly.\n";
            cout << endl;
            return;
        }
        clock_t end_time = clock();
        work_time[i] = double(end_time - start_time) / CLOCKS_PER_SEC;
    }
    Print("Bubble", work_time);  
}

template <class T>
void RunQuickSort(T* array, int size) {
    double work_time[3];
    for (int i = 0; i < 3; ++i) {
        T* new_array = CopyArray(size, array);
        clock_t start_time = clock();
        SortingArrayWithQuickSort(0, 0, size - 1, new_array);
        if (i == 0 && !CheckingIfSortedCorrectly(size, new_array)) {
            cout << "Quick Sort doesn't work correctly.\n";
            cout << endl;
            return;
        }
        clock_t end_time = clock();
        work_time[i] = double(end_time - start_time) / CLOCKS_PER_SEC;
    }
    Print("Quick", work_time);
}

template <class T>
void RunSelectionSort(T* array, int size) {
    double work_time[3];
    for (int i = 0; i < 3; ++i) {
        T* new_array = CopyArray(size, array);
        clock_t start_time = clock();
        SortingArrayWithSelectionSort(size, new_array);
        if (i == 0 && !CheckingIfSortedCorrectly(size, new_array)) {
            cout << "Selection Sort doesn't work correctly.\n";
            cout << endl;
            return;
        }
        clock_t end_time = clock();
        work_time[i] = double(end_time - start_time) / CLOCKS_PER_SEC;
    }
    Print("Selection", work_time);
}

template <class T>
void RunInsertionSort(T* array, int size) {
    double work_time[3];
    for (int i = 0; i < 3; ++i) {
        T* new_array = CopyArray(size, array);
        clock_t start_time = clock();
        SortingArrayWithInsertionSort(size, new_array);
        if (i == 0 && !CheckingIfSortedCorrectly(size, new_array)) {
            cout << "Insertion Sort doesn't work correctly.\n";
            cout << endl;
            return;
        }
        clock_t end_time = clock();
        work_time[i] = double(end_time - start_time) / CLOCKS_PER_SEC;
    }
    Print("Insertion", work_time);
}

template <class T>
void RunShellSort(T* array, int size) {
    double work_time[3];
    for (int i = 0; i < 3; ++i) {
        T* new_array = CopyArray(size, array);
        clock_t start_time = clock();
        SortingArrayWithShellSort(size, new_array);
        if (i == 0 && !CheckingIfSortedCorrectly(size, new_array)) {
            cout << "Shell Sort doesn't work correctly.\n";
            cout << endl;
            return;
        }
        clock_t end_time = clock();
        work_time[i] = double(end_time - start_time) / CLOCKS_PER_SEC;
    }
    Print("Shell", work_time);
}

template <class T>
void RunHeapSort(T* array, int size) {
    double work_time[3];
    for (int i = 0; i < 3; ++i) {
        T* new_array = CopyArray(size, array);
        clock_t start_time = clock();
        SortingArrayWithHeapSort(size, new_array);
        if (i == 0 && !CheckingIfSortedCorrectly(size, new_array)) {
            cout << "Shell Sort doesn't work correctly.\n";
            cout << endl;
            return;
        }
        clock_t end_time = clock();
        work_time[i] = double(end_time - start_time) / CLOCKS_PER_SEC;
    }
    Print("Heap", work_time);
}

template <class T>
void RunMergeSort(T* array, int size) {
    double work_time[3];
    for (int i = 0; i < 3; ++i) {
        T* new_array = CopyArray(size, array);
        clock_t start_time = clock();
        SortingArrayWithMergeSort(size, new_array);
        if (i == 0 && !CheckingIfSortedCorrectly(size, new_array)) {
            cout << "Merge Sort doesn't work correctly.\n";
            cout << endl;
            return;
        }
        clock_t end_time = clock();
        work_time[i] = double(end_time - start_time) / CLOCKS_PER_SEC;
    }
    Print("Merge", work_time);
}
