#include <iostream>
#include "stack.hpp"


Stack::Stack()
{
    m_head = nullptr;
    m_tail = nullptr;
}

Stack::Stack(int size, int value)
{
    nodePtr temp = new node;
    temp->data = value;
    temp->next = nullptr;
    m_head = temp;
    m_tail = temp;
    for (int i = 0; i < size; i++) {
        Push(value);
    }
}

Stack::~Stack()
{
    nodePtr temp = new node;
    while (temp != nullptr) {
        temp = m_head;
        m_head = temp->next;
        delete temp;
    }
}

int Stack::Size() const
{
    int count = 0;
    nodePtr temp = new node;
    temp = m_head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void Stack::Print() const
{
    nodePtr temp = new node;
    temp = m_head;
    while (temp != nullptr) {
        temp = temp->next;
        std::cout << temp << std::endl;
    }
}

void Stack::PrintStack(nodePtr node)
{
    while (node != NULL) {
        std::cout << " " << node->data << std::endl;
        node = node->next;
    }
}

void Stack::Pop()
{
    nodePtr temp = new node;
    temp = m_head;
    if (m_head == nullptr) {
        std::cout << "Stack is empyt" << std::endl;
    }
    else if (m_head->next == nullptr) {
        delete m_head;
    }
    else {
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
    }
}

void Stack::Push(const int& value)
{
    nodePtr temp = new node;
    temp->data = value;
    temp->next = nullptr;
    if (m_head == nullptr) {
        m_head = temp;
        m_tail = temp;
    }
    else {
        m_tail->next = temp;
        m_tail = temp;
    }
}

bool Stack::Empty() const
{
    return m_head == nullptr;
}

int Stack::Top()
{
    nodePtr temp = new node;
    temp = m_head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}