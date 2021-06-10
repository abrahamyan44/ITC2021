#include "../include/Timer.hpp"

void Timer::Start() {
    m_start = clock();
}

double Timer::GetDuration() {
    return double(clock() - m_start) / CLOCKS_PER_SEC;
}