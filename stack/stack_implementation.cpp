#include<iostream>
#include "stack_implementation.hpp"

//constructor
Stack::Stack()
{
    m_head = NULL;
    m_tail = NULL;
}

//constructor which creates stack with given number of elements and with given value
Stack::Stack(int n, int value)
{
    node* tmp = new node;
    tmp->data = value;
    tmp->next = NULL;
    m_head = tmp;
    m_tail = tmp;

    for (int i = 0; i < n - 1; i++) {
          Push(value);
    }
}

//inserts element at the top of the stack 
void Stack::Push(const int& n)
{
    node* tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if (m_head == NULL)
    {
        m_head = tmp;
        m_tail = tmp;
    } else {
        m_tail->next = tmp;
        m_tail = tmp;
    }
}

//prints elements of the Stack
void Stack::Print()
{
    node* tmp;
    tmp = m_head;
    while (tmp != NULL)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

//returns size of the stack
int Stack::Size()
{
    int count = 0;
    node* tmp;
    tmp = m_head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

//removes last element of the stack
void Stack::Pop()
{
     if (m_head == NULL){
         std::cout << "The stack is already empty ";
     } else if (m_head->next == NULL) {
       m_head = NULL;
     } else {
          node* tmp;
          tmp = m_head;
          while (tmp->next->next != NULL)
          {
              tmp = tmp->next;
          }
          delete tmp->next;

          tmp->next = NULL;
     }
}

//returns whether the stack is empty
bool Stack::Empty()
{
    return (m_head == NULL);
} 

//returns top element of the stack
int Stack::Top()
{
    if (m_head == NULL) {
        std::cout << "The stack is empty... " << std::endl;
    } else if (m_head->next == NULL) {
        return m_head->data;
    } else {
        node* tmp;
        tmp = m_head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        return tmp->data;
    }
}

//destructor
Stack::~Stack()
{
    node* tmp = m_head;
    node* nextNode;

    while (tmp != NULL) {
        nextNode = tmp->next;
        delete tmp;
        tmp = nextNode;
    }

}
