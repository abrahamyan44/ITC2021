#ifndef SORTING_HPP
#define SORTING_HPP

namespace ByRubenyans
{
    template <typename T>
    static void BubbleSort(int n, T* array);

    template <typename T>
    static void MergeSort(int n, T* array);

    template <typename T>
    static void QuickSort(int n, T* array);

    template <typename T>
    static void ShellSort(int n, T* array);

    template <typename T>
    static void HeapSort(int n, T* array);

    template <typename T>
    static void InsertionSort(int n, T* array);

    template <typename T>
    static void SelectionSort(int n, T* array);
}

#include "sorting.tpp"
#endif
