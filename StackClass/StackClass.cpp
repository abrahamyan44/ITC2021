#include <iostream>
#include <cassert>
#include "StackClass.hpp"

template <class T>
Stack <T>::Stack () : m_top(0), m_size(0)
{}

template <class T>
Stack <T>::Stack (const T& value, int count) : m_top(0), m_size(0)
{
    for (int i=0; i < count; i++)
    {
        node <T>* temporal = new node <T>(value, m_top);
        m_top = temporal;
        m_size++;
    }
}

template <class T>
Stack <T>::Stack (const Stack <T>& other_stack) : m_top(0), m_size(other_stack.m_size)
{
    node <T>* current = other_stack.m_top;
    m_top = new node <T>;
    m_top->data = current->data;
    m_top->link = 0;

    node <T>* last = m_top;
    current = current->link;
    while (current != 0)
    {
        node <T>* temporal = new node <T>;
        temporal->data = current->data;
        temporal->link = 0;
        last->link = temporal;
        last = temporal;
        current = current->link;
    }
}

template <class T>
Stack <T>::~Stack ()
{
    std::cout << "Destructed!" << std::endl;
    node <T>* temporal = m_top;
    while (temporal->link != 0)
    {
        temporal = temporal->link;
        delete m_top;
        m_top = temporal;
    }
    m_size = 0;
}

template <class T>
void Stack <T>::Pop ()
{
    if (!IsEmpty())
    {
        node <T>* temporal = m_top->link;
        delete m_top;
        m_top = temporal;
        m_size--;
    }
    else
    {
        std::cout << "Nothing to pop!" << std::endl;
    }
}

template <class T>
void Stack <T>::Push (const T& value)
{
    node <T>* temporal = new node <T>;
    if (IsEmpty())
    {
        temporal->data = value;
        m_top = temporal;
    }
    else
    {
        temporal->data = value;
        temporal->link = m_top;
        m_top = temporal;
    }
    m_size++;
}

template <class T>
int Stack <T>::GetSize () const
{
    return m_size;
}

template <class T>
bool Stack <T>::IsEmpty () const
{
    return (m_size == 0);
}

template <class T>
T& Stack <T>::GetTop ()
{
        assert(m_top != 0);
        return m_top->data;
}

template <class T>
void Stack <T>::Print ()
{
    if (IsEmpty())
    {
        std::cout << "The stack is empty for to be printed!" << std::endl;
    }
    else
    {
        node <T>* temporal = m_top;
        while (temporal)
        {
            std::cout << temporal->data << " ";
            temporal = temporal->link;
        }
    }
    std::cout << std::endl;
}


int main()
{
    Stack <int> stack1;
    stack1.Print(); 
    Stack <int> stack2(9, 4);
    std::cout << "stack2's elements are: " << std::endl;
    stack2.Print();
    Stack <int> stack3(stack2);
    std::cout << "stack3's elements are the copy of stack2: " << std::endl;
    stack3.Print(); 
    stack1.Push(1);
    stack1.Push(2);
    stack1.Push(3);
    stack1.Push(4);
    std::cout << "stack1's elements after pushing them: " << std::endl;
    stack1.Print();
    Stack <int> stack4(stack1);
    std::cout << "stack4's elements are the copy of stack1: " << std::endl;
    stack4.Print();
    stack1.Pop();
    std::cout << "stack1's elements after poping: " << std::endl;
    stack1.Print();
    stack2.Pop();
    std::cout << "stack2's elements after poping: " <<std::endl;
    stack2.Print();
    std::cout << "stack1's size is: " << stack1.GetSize() << std::endl;
    std::cout << "stack1's top is: " << stack1.GetTop() << std::endl;
    
    if (!stack1.IsEmpty())
    {
        std::cout << "stack1 is not empty." << std::endl;
    }
    
    return 0;
}
