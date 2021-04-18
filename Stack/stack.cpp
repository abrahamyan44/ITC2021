//- --Stack.cpp---
#include <iostream>
#include "stack.hpp"

//Default constructor
//Constructs an empty container, with no elements.
template <typename T>
Stack<T>::Stack()
    :m_top()
    ,m_size(0)
{
    std::cout << "In default constructor\n";
}

//Fill constructor
//Constructs a container with n elements. 
//Each element is a copy of val.
template <typename T>
Stack<T>::Stack(int size, T val)
    :m_top(size,val)
    ,m_size(size)
{
    std::cout << "In constructor\n";
}

//Copy constructor
//Constructs a container with a copy of each 
//of the elements from another stack.
template <typename T>
Stack<T>::Stack(const Stack& other)
    :m_top(other.m_top)
    ,m_size(other.m_size)
{
    std::cout << "In copy constructor\n";
}

//Destroys the container object.
template <typename T>
Stack<T>::~Stack()
{
    std::cout << "In destructor\n";
}

//Checks the stack is empty
template <typename T>
bool Stack<T>::isEmpty() const
{
    return(m_size < 0 ? true : false);
}

//Inserts a new element at the top of the stack,
//above its current top element.
template <typename T>
void Stack<T>::Push(const T& val)
{
    m_top.InsertEnd(val);
}

//Removes the element on top of the stack, 
//effectively reducing its size by one.
template <typename T>
void Stack<T>::Pop()
{
    if (!isEmpty())
    {
        m_top.EraseEnd();
        --m_size;
    }
}

//Returns the number of elements in the stack.
template <typename T>
int Stack<T>::Size() const
{
    return m_size;
}

//Returns a reference to the top element in the stack.
template <typename T>
T& Stack<T>::top()
{
    return m_top.tail();
}

template class Stack<int>;
