#pragma once
using namespace std;

template <class T>
class Timer {
private:
    int s_test_count;
    vector<double*> m_timer;
    map<double*, string> m_match;
    clock_t m_start;
public:
    Timer(int test_count);
    void Start();
    void Run(void (*Sort) (int, T*), int size, T* array, string name);
    double GetDuration();
	double GetAverageTime(double* work_time);
    void SortTimer();
    void SortByAverageTime();
	string NumberToString(double number);
	string LineToString(double* work_time);
    void Print();
};

void PrintSide(int length) {
	cout << endl;
	for (int i = 0; i < length; ++i) {
		cout << '_';
	}
	cout << endl;
	cout << endl;
}

void PrintTitle() {
	string s[] = {"Function name", "Minimum time", "Average time", "Maximum time"};
	for (int i = 0; i < 4; ++i) {
		int begin = (14 - s[i].length()) / 2;
		int end = 14 - s[i].length() - begin;
		for (int j = 0; j < begin; ++j) {
			cout << ' ';
		}
		cout << s[i];
		for (int j = 0; j < end; ++j) {
			cout << ' ';
		}
		cout << '|';
	}
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
        Sorting(size, CopyArray(size, array));
        m_timer[m_timer.size() - 1][i] = GetDuration();
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
	return string();
}

template <class T>
string Timer<T>::LineToString(double* work_time) {
	string sort_name = m_match[work_time];
	string line = m_match[work_time];
	for (int i = 14; i > sort_name.length(); --i) {
		line.push_back(' ');
	}
	for (int i = 0; i < s_test_count; ++i) {
		line.push_back('|');
		line += NumberToString(work_time[i]);
	}
	return line;
}

template <class T>
void Timer<T>::Print() {
    SortByAverageTime();
	PrintTitle();
    for (int i = 0; i < m_timer.size(); ++i) {
   		string line = LineToString(m_timer[i]);
	    PrintSide(line.length());
        cout << line;
    }
}
