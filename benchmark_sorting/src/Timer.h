#pragma once
using namespace std;

template <class T>
class Timer {
private:
    int s_test_count;
    vector<double*> m_timer;
    map<double*, string> m_match;
    clock_t m_start;
private:
    void Start();
    double GetDuration();
	double GetAverageTime(double* work_time);
    void SortTimer();
    void SortByAverageTime();
	void PrintSide(int length);
	string GetWord(string text);
	bool IsSorted(int size, T* array);
public:
	Timer(int test_count);
    void Run(void (*Sort) (int, T*), int size, T* array, string name);
    string NumberToString(double number);
	string LineToString(double* work_time);
    void PrintTable();
	~Timer();
};

template <class T>
Timer<T>::~Timer(){
	for (int i = 0; i < m_timer.size(); ++i) {
		delete[] m_timer[i];
	}
	m_match.clear();
}
		
template <class T>
void Timer<T>::PrintSide(int length) {
	cout << endl;
	for (int i = 0; i < length; ++i) {
		cout << '_';
	}
	cout << endl;
	cout << endl;
}

template <class T>
string Timer<T>::GetWord(string text) {
	int begin = (14 - text.length()) / 2;
	int end = 14 - text.length() - begin;
	string word;
	for (int j = 0; j < begin; ++j) {
		word.push_back(' ');
	}
	word += text;
	for (int j = 0; j < end; ++j) {
		word.push_back(' ');
	}
	word.push_back('|');
	return word;
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
bool Timer<T>::IsSorted(int size, T* array) {
	for (int i = 1; i < size; ++i) {
			if (array[i] < array[i - 1]) {
				return false;
		}
	}
	return true;
}

template <class T>
Timer<T>::Timer(int test_count) {
    s_test_count = test_count;
}

template <class T>
void Timer<T>::Start() {
    m_start = clock();
}

template <class T>
void Timer<T>::Run(void (*Sorting) (int, T*), int size, T* array, string name) {
    m_timer.push_back(new double[s_test_count]);
	for (int i = 0; i < s_test_count; ++i) {
		Start();
		T* new_array = CopyArray(size, array);
		Sorting(size, new_array);
		m_timer[m_timer.size() - 1][i] = GetDuration();
		if (i == 0 && !IsSorted(size, new_array)) {
			throw name + "sort does not work correctly!!!";
			delete[] new_array;
			return;
		}
		delete[] new_array;
	}
    SortTimer();
    m_match.insert(pair<double*, string>(m_timer[m_timer.size() - 1], name + "sort"));
}

template <class T>
double Timer<T>::GetDuration() {
    return double(clock() - m_start) / CLOCKS_PER_SEC;
}

template <class T>
double Timer<T>::GetAverageTime(double* work_time) {
	double sum = 0;
	for (int i = 0; i < s_test_count; ++i) {
		sum += work_time[i];
	}
	return sum / s_test_count;
}

template <class T>
void Timer<T>::SortTimer() {
    std::sort(m_timer[m_timer.size() - 1], m_timer[m_timer.size() - 1] + s_test_count);
}

template <class T>
void Timer<T>::SortByAverageTime() {
    for (int i = 0; i < m_timer.size(); ++i) {
        for (int j = 1; j < m_timer.size() - i; ++j) {
            if (GetAverageTime(m_timer[j - 1]) > GetAverageTime(m_timer[j])) {
                swap(m_timer[j - 1], m_timer[j]);
            }
        }
    }
}

template <class T>
string Timer<T>::NumberToString(double number) {
	std::ostringstream strs;
	strs << number;
	std::string str = strs.str();
	return str.substr(0, 10);
}

template <class T>
string Timer<T>::LineToString(double* work_time) {
	string sort_name = m_match[work_time];
	string line = "| " + m_match[work_time];
	for (int i = 14; i > sort_name.length(); --i) {
		line.push_back(' ');
	}
	line.push_back('|');
	for (int i = 0; i < s_test_count; ++i) {
		line.push_back('|');
		line += GetWord(NumberToString(work_time[i]));
	}
	return line;
}

template <class T>
void Timer<T>::PrintTable() {
    SortByAverageTime();
	string line = "| " + GetWord("Function name") + "|" +  GetWord("Minimum time") + "|" +  GetWord("Average time") + "|" +  GetWord("Maximum time");
	PrintSide(line.length());
	cout << line;
	PrintSide(line.length());
    for (int i = 0; i < m_timer.size(); ++i) {
   		string line = LineToString(m_timer[i]);
        cout << line;
		PrintSide(line.length());
    }
	cout << endl;
}
