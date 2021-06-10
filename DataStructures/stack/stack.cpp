#include <iostream>
#include "stack.h"

template <class T>
Stack<T>::Stack() 
    :m_last(nullptr), m_size(0) {}

template <class T>
Stack<T>::Stack(const int& size, const T& value) 
    :m_size(0), m_last(nullptr) 
{
    for(int i = 0; i < size; ++i) 
    {
        Push(value);
    }
}

template <class T>
Stack<T>::Stack(const Stack& other)
    :m_size(other.m_size), m_last(nullptr) 
{
    Node* q = other.m_last;
    m_last = new Node(q->data);
    Node* g = m_last;
    while(q->prev) 
    {
        q = q->prev;
        g->prev = new Node(q->data);
        g = g->prev;
    }
}

template <class T>
Stack<T>::~Stack()
{
    Node* q = m_last;
    while(q)
    {
        Node* g = q;
        q = q->prev;
        delete g;
    }
}

template <class T>
void Stack<T>::Pop()
{
    if(IsEmpty()) 
    {
        return;
    }
    Node* q = m_last;
    m_last = m_last->prev;
    --m_size;
    delete q;
}

template <class T>
void Stack<T>::Push(const T& data)
{
    Node* q = new Node(data);
    q->prev = m_last;
    m_last = q;
    ++m_size;
}

template <class T>
int Stack<T>::GetSize() const
{
    return m_size;
}

template <class T>
bool Stack<T>::IsEmpty() const
{
    return m_size == 0;
}

template <class T>
T& Stack<T>::GetTop()
{
    return m_last->data;
}


int main() {
    Stack<int> a;
    for(int i = 0; i < 10; ++i) {
        a.Push(i);
    }
    Stack<int> b(a);
    int size = a.GetSize();
    for(int i = 0; i < size; ++i) {
        std::cout << b.GetTop() << " ";
        b.Pop();
    }
    return 0;
}