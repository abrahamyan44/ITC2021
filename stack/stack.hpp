struct node
{
    int data;
    node* next;
};

class Stack {
public:
    typedef struct node* nodePtr;

private: 
    nodePtr m_head;
    nodePtr m_tail;

public:
    Stack();
    Stack(const Stack&);
    Stack(int , int );
    ~Stack();

    int Size() const;
    void Print() const;
    void PrintStack(nodePtr);
    void Pop();
    void Push(const int&);
    bool Empty() const;
    int Top();
};