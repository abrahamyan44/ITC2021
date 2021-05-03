#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Timer.hpp"

class BenchmarkTable	
{
private:
    int m_test_count;
    std::vector<double*> m_timer;
    std::map<double*, std::string> m_match;
private:
	double GetAverageTime(double* work_time);
    void SortTimer();
    void SortByAverageTime();
	void PrintSide(int length);
	std::string GetWord(const std::string& text);
	template <class T>
	bool IsSorted(int size, T* array);
public:
	BenchmarkTable(int);
	template <class T>
    void Run(void (*Sort) (int, T*), int size,
		T* array, std::string name);
    std::string NumberToString(double number);
	std::string LineToString(double* work_time);
    void PrintTable();
};


template <class T>
T* CopyArray(int size, T* array) {
    T* new_array = new T[size];
	std::copy(array, array + size, new_array);
    return new_array;
}

template <class T>
void BenchmarkTable::Run(void (*Sorting) (int, T*), int size, T* array, std::string name) {
    m_timer.push_back(new double[m_test_count]);
	Timer time;
	for (int i = 0; i < m_test_count; ++i) {
		time.Start();
		T* new_array = CopyArray(size, array);
		Sorting(size, new_array);
		m_timer[m_timer.size() - 1][i] = time.GetDuration();
		if (i == 0 && !IsSorted(size, new_array)) {
			throw name + "sort does not work correctly!!!";
			delete[] new_array;
			return;
		}
		delete[] new_array;
	}
    SortTimer();
    m_match.insert(pair<double*, std::string>(m_timer[m_timer.size() - 1], name + "sort"));
}

template <class T>
bool BenchmarkTable::IsSorted(int size, T* array) {
	if (size == 1){
		return true;
	}
	return std::find_if(array + 1, array + size, [](const T& i){
		return i < *(&i - 1); } ) == array + size;
}


#endif //BENCHMARK_HPP