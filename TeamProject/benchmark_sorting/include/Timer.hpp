#pragma once
#include <iostream>
using namespace std;

class Timer 
{
private:
	clock_t m_start;
public:
    void Start();
    double GetDuration();	
};