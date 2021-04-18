
//---Stack.h---
#ifndef _STACK_HPP
#define _STACK_HPP

#include "List.hpp"

template <typename T>
class Stack
{
private:
    List<T> m_top;
    int m_size;
   
public:
    Stack();
    Stack(int, T);
    Stack(const Stack&);
    ~Stack();
    void Push(const T&);
    void Pop();
    bool isEmpty() const;
    int Size() const;
    T& top();
};
#endif //_STACK_HPP
