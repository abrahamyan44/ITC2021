#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <sorting.hpp>
#include "duration.hpp"


namespace test
{
    void Print(std::string sort_name, long double* time)
    {
        ByRubenyans::BubbleSort(3, time);
        std::cout << std::setw(5) << "| Sort program  | " << std::setw(5) << "duration   |" << std::endl;
        std::cout << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(10) << time[0] << "ms |" << std::setw(5) << "minimume  |" << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(10) << std::setprecision(4) << (time[0] + time[1] + time[2]) / 3 << "ms |" << std::setw(5) << "average   |" << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(10) << time[2] << "ms |"<< std::setw(5) << "maximume  |" << std::endl;
        std::cout << std::endl;
    }

    void Print1(std::string sort_name, long double time) 
    {
        std::cout << "|" << sort_name << " \t|\t" << time << "ms |" << "   " << std::endl;
    }

    void Print2(std::string sort_name, long double* time)
    {
        ByRubenyans::BubbleSort(2, time);
        std::cout << std::setw(5) << "| Sort program  | " << std::setw(5) << "duration  |" << std::endl;
        std::cout << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(5) << time[0] << "ms |" << "minimume|" << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(5) << std::setprecision(4) << (time[0] + time[1]) / 2 << "ms |" << "average |" << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(5) << time[1] << "ms |" << "maximume|" << std::endl;
        std::cout << std::endl;
    }

    template <typename T>
    void TestingShell(T* array, int n, int test_count)
    {
        if(test_count == 1) {
            Print1("ShellSort", duration::Duration(ByRubenyans::ShellSort, n, array));
		}
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(ByRubenyans::ShellSort, n, array);
            }
            Print2("ShellSort", time);
        }
        if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(ByRubenyans::ShellSort, n, array);
            }
            Print("ShellSort", time);
        }
    }

    template <typename T>
    void TestingHeap(T* array, int n, int test_count)
    {
        if(test_count == 1) {
            Print1("HeapSort", duration::Duration(ByRubenyans::HeapSort, n, array));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(ByRubenyans::HeapSort, n, array);
            }
            Print2("HeapSort", time);
        }
        if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(ByRubenyans::HeapSort, n, array);
            }
            Print("HeapSort", time);
        }
    }
 
    template <typename T>
    void TestingMerge(T* array, int n, int test_count)
    {
        if(test_count == 1) {
            Print1("MergeSort", duration::Duration(ByRubenyans::MergeSort, n, array));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(ByRubenyans::MergeSort, n, array);
            }
            Print2("MergeSort", time);
        }
        if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(ByRubenyans::MergeSort, n, array);
            }
            Print("MergeSort", time);
         }
    }

    template <typename T>
    void TestingBubble(T* array, int n, int test_count)
    {
        if(test_count == 1) {
            Print1("BubbleSort", duration::Duration(ByRubenyans::BubbleSort, n, array));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(ByRubenyans::BubbleSort, n, array);
            }
            Print2("BubbleSort", time);
		}
        if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(ByRubenyans::BubbleSort, n, array);
            }
            Print("BubbleSort", time);
        }
    }

    template <typename T>
    void TestingQuick(T* array, int n, int test_count)
    {
        if(test_count == 1) {
            Print1("QuickSort", duration::Duration(ByRubenyans::QuickSort, n, array));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(ByRubenyans::QuickSort, n, array);
            }
            Print2("QuickSort", time);
        }
        if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(ByRubenyans::QuickSort, n, array);
            }
            Print("QuickSort", time);
        }
    }
}

#endif
