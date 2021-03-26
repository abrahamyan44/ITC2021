#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#define MAX_SIZE 100

template<class T>
class Stack{

private:
T*data;
int size;

public:
Stack();
Stack(const int & size, const T& value);
~Stack();
T& top();
int getsize()const;
void push(const T& value);
void pop();
bool empty()const;
Stack(const Stack<T>& stack);
void print();
};
template class Stack<int>;

#endif
