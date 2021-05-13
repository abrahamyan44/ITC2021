#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class Stack {
public:
//    typedef struct node* nodePtr;

private: 
    node* m_head;
    node* m_tail;

public:
    Stack();
    Stack(const Stack&);
    Stack(int , int );
    ~Stack();

    int Size() const;
    void Print() const;
    void PrintStack();
    void Pop();
    void Push(const int&);
    bool Empty() const;
    int Top();
};
