#include "duration.hpp"


namespace test
{
	void Print(std::string sort_name, long double time[])
	{
		sorting::BubbleSort(time, 3);
		std::cout << std::setw(5) << "| Sort program  | " << std::setw(5) << "duration  |" << std::endl;
		std::cout << std::endl;
		std::cout << "|" << sort_name << "|" << std::setw(5) << time[0] << "ms |" << "minimume|" << std::endl;
		std::cout << "|" << sort_name << "|" << std::setw(5) << time[1] << "ms |" << "average |" << std::endl;
		std::cout << "|" << sort_name << "|" << std::setw(5) << time[2] << "ms |" << "maximume|" << std::endl;
		std::cout << std::endl;

	}

	void Print1(std::string sort_name, long double time) 
	{
		std::cout << std::setw(5) << "| Sort program| " << std::setw(5) << "duration|" << std::endl;
        std::cout << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(5) << time << "ms |" << "   " << std::endl;
		std::cout << std::endl;
	}

	void Print2(std::string sort_name, long double time[])
    {
        sorting::BubbleSort(time, 2);
        std::cout << std::setw(5) << "| Sort program  | " << std::setw(5) << "duration  |" << std::endl;
        std::cout << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(5) << time[0] << "ms |" << "minimume|" << std::endl;
        std::cout << "|" << sort_name << "|" << std::setw(5) << time[1] << "ms |" << "maximume|" << std::endl;
		std::cout << std::endl;
	}


	template <class T>
    void TestingShell(T* array, int n, int test_count)
    {
		if(test_count == 1) {
			Print1("ShellSort", duration::Duration(sorting::ShellSort, array, n));
		}
		if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(sorting::ShellSort, array, n);
            }
            Print2("ShellSort", time);
        }
		if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(sorting::ShellSort, array, n);
            }
            Print("ShellSort", time);
		}
    }

	template <class T>
    void TestingHeap(T* array, int n, int test_count)
    {
		if(test_count == 1) {
			Print1("HeapSort", duration::Duration(sorting::HeapSort, array, n));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(sorting::HeapSort, array, n);
            }
            Print2("HeapSort", time);
        }
		if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(sorting::HeapSort, array, n);
            }
            Print("HeapSort", time);
		}
    }
 
	template <class T>
	void TestingMerge(T* array, int n, int test_count)
    {
		if(test_count == 1) {
            Print1("MergeSort", duration::Duration(sorting::MergeSort, array, n));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(sorting::MergeSort, array, n);
            }
            Print2("MergeSort", time);
        }
		if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(sorting::MergeSort, array, n);
            }
            Print("MergeSort", time);
		}
    }

	template <class T>
    void TestingBubble(T* array, int n, int test_count)
    {
		if(test_count == 1) {
            Print1("BubbleSort", duration::Duration(sorting::BubbleSort, array, n));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(sorting::BubbleSort, array, n);
            }
            Print2("BubbleSort", time);
        }
		if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(sorting::BubbleSort, array, n);
            }
            Print("BubbleSort", time);
		}
    }

	template <class T>
	void TestingQuick(T* array, int n, int test_count)
    {
		if(test_count == 1) {
            Print1("QuickSort", duration::Duration(sorting::QuickSort, array, n));
        }
        if(test_count == 2) {
            long double time[2];
            for(int i = 0; i < 2; ++i) {
                time[i] = duration::Duration(sorting::QuickSort, array, n);
            }
            Print2("QuickSort", time);
        }
		if(test_count == 3) {
            long double time[3];
            for(int i = 0; i < 3; ++i) {
                time[i] = duration::Duration(sorting::QuickSort, array, n);
            }
            Print("QuickSort", time);
		}
    }
}


