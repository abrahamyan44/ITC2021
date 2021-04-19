#include <iostream>
#include <cassert>
#include <chrono>
#include <iomanip>

namespace sorting
{
    template <class T>
    void Swap (T& a, T& b) {
        T k = a;
        a = b;
        b = k;
    }

    template <class T>
    void BubbleSort (T* array, int n)
    {
        for (int i = 0; i < n; ++i) {
            bool swap = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (array[j] > array[j + 1]) {
                    Swap(array[j + 1], array[j]);
                    swap = true;
                }
            }
            if (swap == false) {
                break;
            }
        }
    }

    template <class T>
    void Merge (T* array, int s, int m, int n)
    {
        int n1 = m - s + 1;
        int n2 = n - m;
        T* array1 = new int[n1];
        T* array2 = new int[n2];
        for (int i = 0; i < n1; ++i) {
            array1[i] = array[s + i];
        }
        for (int j = 0; j < n2; ++j) {
            array2[j] = array[m + 1 + j];
        }
        int i = 0;
        int j = 0;
        int k = s;
        while (i < n1 && j < n2) {
            if (array1[i] <= array2[j]) {
                array[k] = array1[i];
                ++i;
            } else {
                array[k] = array2[j];
                ++j;
            }
            ++k;
        }
        while (i < n1) {
            array[k] = array1[i];
            ++i;
            ++k;
        }
        while (j < n2) {
            array[k] = array2[j];
            ++j;
            ++k;
        }
        delete [] array1;
        delete [] array2;
    }

	template <class T>
    void MergeSort (T* array, int s, int n)
    {
        if (s < n) {
            int mid = s + (n - s) / 2;
            MergeSort(array, s, mid);
            MergeSort(array, mid + 1, n);
            Merge(array, s, mid, n);
        }
    }

    template <class T>
    int SetPartition (T* array, int s, int n)
    {
        T pivot = array[n];
        int i = s - 1;
        for(int j = s; j <= n; ++j) {
            if(array[j] < pivot) {
                ++i;
                Swap(array[i], array[j]);
            }
        }
        Swap(array[i + 1], array[n]);
        return i + 1;
    }

	template <class T>
    void QuickSort (T* array, int s, int n)
    {
        if(s <= n) {
            int position = SetPartition(array, s, n);
            QuickSort(array, s, position - 1);
            QuickSort(array, position + 1, n);
        }

    }

	template <class T>
    void ShellSort(T* array, int n)
    {
        for(int interval = n / 2; interval > 0; interval /= 2) {
            for(int i = interval; i < n; ++i) {
                T temp = array[i];
                int j;
                for(j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                    array[j] = array[j - interval];
                }
                array[j] = temp;
            }
        }
    }

	template <class T>
    void Heapify(T* array, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && array[left] > array[largest]) {
            largest = left;
        }
        if(right < n && array[right] > array[largest]) {
            largest = right;
        }
        if(largest != i) {
            Swap(array[largest], array[i]);
            Heapify(array, n, largest);
        }
    }

	template <class T>
    void HeapSort(T* array, int n)
    {
        for(int i = n / 2 - 1; i >= 0; --i) {
            Heapify(array, n, i);
        }
        for(int i = n - 1; i >= 0; --i) {
            Swap(array[0], array[i]);
            Heapify(array, i, 0);
        }
    }
}





     
