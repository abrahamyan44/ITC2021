#ifndef DURATION_H
#define DURATION_H

#include <chrono>

namespace duration
{
    template <typename T>
    T* CopyArray(T* array, int n) {
        T* new_array = new T[n];
        for(int i = 0; i < n; ++i) {
            new_array[i] = array[i];
        }
        return new_array;
    }

    template <typename T>
    bool SortVerification(T* array, int n)
    {
        bool is_sorted;
        for(int i = 0; i < n - 1; ++i) {
            is_sorted = false;
            if(array[i] <= array[i + 1]) {
                is_sorted = true;
            }
        }
        return is_sorted;
    }

    template <typename T>
    long double Duration(void (*func_name)(T*, int, int), T* array, int n)
    {
        T* new_array = CopyArray(array, n);
        auto start = std::chrono::system_clock::now();
        (*func_name)(new_array, 0, n - 1);
        auto stop = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        if(SortVerification(new_array, n)) {
            delete [] new_array;
            return duration;
        }
        else {
            return -1;
        }
    }

    template <typename T>
    long double Duration(void (*func_name)(T*, int), T* array, int n)
    {
        T* new_array = CopyArray(array, n);
        auto start = std::chrono::system_clock::now();
        (*func_name)(new_array, n);
        auto stop = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        if(SortVerification(new_array, n)) {
            delete [] new_array;
            return duration;
        }
        else {
            return -1;
        }
    }
}


#endif