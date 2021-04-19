#include "sorting.hpp"

namespace duration
{
    template <class T>
    T* CopyArray(T* array, int n) {
        T* new_array = new int[n];
        for(int i = 0; i < n; ++i) {
            new_array[i] = array[i];
        }
        return new_array;
    }

    template <class T>
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

    template <class T>
    long double Duration(void (*func_name)(T*, int, int), T* array, int n)
    {
        T* new_array = CopyArray(array, n);
        auto start = std::chrono::system_clock::now();
        (*func_name)(new_array, 0, n - 1);
        auto stop = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        if(SortVerification(new_array, n)) {
            return duration;
        }
        else {
            return -1;
        }
        delete [] new_array;
    }

    template <class T>
    long double Duration(void (*func_name)(T*, int), T* array, int n)
    {
        T* new_array = CopyArray(array, n);
        auto start = std::chrono::system_clock::now();
        (*func_name)(new_array, n);
        auto stop = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        if(SortVerification(new_array, n)) {
            return duration;
        }
        else {
            return -1;
        }
        delete [] new_array;
    }
}



