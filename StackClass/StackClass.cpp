#include <iostream>
#include <cassert>
#include "StackClass.hpp"

template <class T>
Stack <T>::Stack() : m_top(0), m_size(0)
{}

template <class T>
Stack <T>::Stack (const T& value, int count) : m_top(0), m_size(0)
{
    for (int i=0; i < count; i++)
    {
        Node <T>* temp = new Node <T>(value, m_top);
        m_top = temp;
        m_size++;
    }
}

template <class T>
Stack <T>::Stack(const Stack <T>& x) : m_top(0), m_size(x.m_size)
{
    Node <T>* current = x.m_top;
    m_top = new Node <T>;
    m_top->data = current->data;
    m_top->link = 0;

    Node <T>* last = m_top;
    current = current->link;
    while (current != 0)
    {
        Node <T>* temp = new Node <T>;
        temp->data = current->data;
        temp->link = 0;
        last->link = temp;
        last = temp;
        current = current->link;
    }
}

template <class T>
Stack <T>::~Stack()
{
    std::cout << "Destructed!" << std::endl;
    Node <T>* temp = m_top;
    while (temp->link != 0)
    {
        temp = temp->link;
        delete m_top;
        m_top = temp;
    }
    m_size = 0;
}

template <class T>
void Stack <T>::Pop()
{
    if (!IsEmpty())
    {
        Node <T>* temp = m_top->link;
        delete m_top;
        m_top = temp;
        m_size--;
    }
    else
    {
            std::cout << "Nothing to pop!" << std::endl;
    }
}

template <class T>
void Stack <T>::Push(const T& value)
{
    Node <T>* temp = new Node <T>;
    if (IsEmpty())
    {
        temp->data = value;
        m_top = temp;
    }
    else
    {
        temp->data = value;
        temp->link = m_top;
        m_top = temp;
    }
    m_size++;
}

template <class T>
int Stack <T>::GetSize() const
{
    return m_size;
}

template <class T>
bool Stack <T>::IsEmpty() const
{
    return (m_size == 0);
}

template <class T>
T& Stack <T>::GetTop()
{
        assert(m_top != 0);
        return m_top->data;
}

template <class T>
void Stack <T>::Print()
{
    if (IsEmpty())
    {
        std::cout << "The stack is empty for to be printed!" << std::endl;
    }
    else
    {
        Node <T>* temp = m_top;
        while (temp)
        {
            std::cout << temp->data << " ";
            temp = temp->link;
        }
    }
    std::cout << std::endl;
}


int main()
{
    Stack <int> s1;
    s1.Print(); 
    Stack <int> s2(9, 4);
    std::cout << "s2's elements are: " << std::endl;
    s2.Print();
    Stack <int> s3(s2);
    std::cout << "s3's elements are the copy of s2: " << std::endl;
    s3.Print(); 
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    std::cout << "s1's elements after pushing them: " << std::endl;
    s1.Print();
    Stack <int> s4(s1);
    std::cout << "s4's elements are the copy of s1: " << std::endl;
    s4.Print();
    s1.Pop();
    std::cout << "s1's elements after poping: " << std::endl;
    s1.Print();
    s2.Pop();
    std::cout << "s2's elements after poping: " <<std::endl;
    s2.Print();
    std::cout << "s1's size is: " << s1.GetSize() << std::endl;
    std::cout << "s1's top is: " << s1.GetTop() << std::endl;
    
    if (!s1.IsEmpty())
    {
        std::cout << "s1 is not empty." << std::endl;
    }
    
    return 0;
}

