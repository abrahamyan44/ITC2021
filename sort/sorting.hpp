#ifndef SORTING_HPP
#define SORTING_HPP

namespace ByRubenyans
{
    template <typename T>
    void Swap(T& a, T& b);

    template <typename T>
    void BubbleSort(T* array, int n);

    template <typename T>
    void MergeHelper(T* array, T* array1, T* array2, int n1, int n2, int s);

    template <typename T>
    void Merge(T* array, int s, int m, int n);

    template <typename T>
    void MergeSort(T* array, int s, int n);

    template <typename T>
    int SetPartition(T* array, int s, int n);

    template <typename T>
    void QuickSort(T* array, int s, int n);

    template <typename T>
    void ShellSort(T* array, int n);

    template <typename T>
    void Heapify(T* array, int n, int i);

    template <typename T>
    void HeapSort(T* array, int n);

    template <typename T>
    void InsertionSort(T* array, int n);

    template <typename T>
    void SelectionSort(T* array, int n);

}
#endif

#include "sorting.tpp"

