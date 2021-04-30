#include "BenchmarkTable.hpp"
#include <algorithm>

void BenchmarkTable::PrintSide(int length) {
	std::cout << std::endl;
	for (int i = 0; i < length; ++i) {
		std::cout << '_';
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

std::string BenchmarkTable::GetWord(const std::string& text)
{
	int begin = (14 - text.length()) / 2;
	int end = 14 - text.length() - begin;
	std::string word(begin, ' ');
	word += text;
	for (int j = 0; j < end; ++j) {
		word.push_back(' ');
	}
	word.push_back('|');
	return word;
}

BenchmarkTable::BenchmarkTable(int test_count) {
    m_test_count = test_count;
}

double BenchmarkTable::GetAverageTime(double* work_time) {
	double sum = 0;
	for (int i = 0; i < m_test_count; ++i) {
		sum += work_time[i];
	}
	return sum / m_test_count;
}

void BenchmarkTable::SortTimer() {
	sort(m_timer[m_timer.size() - 1], m_timer[m_timer.size() - 1] + m_test_count);
}

void BenchmarkTable::SortByAverageTime() {
    for (int i = 0; i < m_timer.size(); ++i) {
        for (int j = 1; j < m_timer.size() - i; ++j) {
            if (GetAverageTime(m_timer[j - 1]) > GetAverageTime(m_timer[j])) {
                swap(m_timer[j - 1], m_timer[j]);
            }
        }
    }
}

std::string BenchmarkTable::NumberToString(double number) {
	std::ostringstream strs;
	strs << number;
	std::string str = strs.str();
	return str.substr(0, 10);
}

std::string BenchmarkTable::LineToString(double* work_time) {
	std::string sort_name = m_match[work_time];
	std::string line = "| " + m_match[work_time];
	for (int i = 14; i > sort_name.length(); --i) {
		line.push_back(' ');
	}
	line.push_back('|');
	for (int i = 0; i < m_test_count; ++i) {
		line.push_back('|');
		line += GetWord(NumberToString(work_time[i]));
	}
	return line;
}

void BenchmarkTable::PrintTable() {
    SortByAverageTime();
	std::string line = "| " + GetWord("Function name") + "|" +  GetWord("Minimum time") + "|" +  GetWord("Average time") + "|" +  GetWord("Maximum time");
	PrintSide(line.length());
	std::cout << line;
	PrintSide(line.length());
    for (int i = 0; i < m_timer.size(); ++i) {
   		std::string line = LineToString(m_timer[i]);
        std::cout << line;
		PrintSide(line.length());
    }
	std::cout << std::endl;
}