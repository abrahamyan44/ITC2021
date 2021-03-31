#include<iostream>

class Stack
{
private: 
    struct node {
        int data;
        node* next;
    };
    node* m_head;
    node* m_tail;

public: 
    Stack();
    Stack(int n, int val);
    void Push(const int&);
    int Size();
    void Print();
    void Pop();
    bool Empty();
    int Top();
    ~Stack();
};
