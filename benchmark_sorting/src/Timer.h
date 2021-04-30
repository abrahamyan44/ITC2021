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
    void Run(void (*Sorting) (int, T*), int size, T* array, string name);
    double GetDuration();
    void SortTimer();
    void SortByAverageTime();
    void Print();
};

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
    m_match.insert(pair<double*, string>(m_timer[m_timer.size() - 1], name));
}

template <class T>
double Timer<T>::GetDuration() {
    return double(clock() - m_start) / CLOCKS_PER_SEC;
}

template <class T>
void Timer<T>::SortTimer() {
    std::sort(m_timer[m_timer.size() - 1], m_timer[m_timer.size() - 1] + s_test_count);
}

template <class T>
void Timer<T>::SortByAverageTime() {
    for (int i = 0; i < m_timer.size(); ++i) {
        for (int j = 1; j < m_timer.size() - i; ++j) {
            if (m_timer[j - 1][s_test_count / 2] > m_timer[j][s_test_count / 2]) {
                swap(m_timer[j - 1], m_timer[j]);
            }
        }
    }
}

template <class T>
void Timer<T>::Print() {
    SortByAverageTime();
    for (int i = 0; i < m_timer.size(); ++i) {
        cout << m_match[m_timer[i]] << "sort";
        for (int j = 0; j < s_test_count; ++j) {
            cout << setprecision(6) << " " << m_timer[i][j];
        }
        cout << endl;
    }
}