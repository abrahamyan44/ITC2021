#pragma once

template <class T>
class Stack 
{
    struct Node 
    {
        Node* prev;
        T data;

        Node(const T& data) 
            :data(data), prev(nullptr) {}
    };

    /////////////////////////////////////////////////////////////////////////

    Node* m_last;
    int m_size;

public:
    Stack();
    Stack(const int& size, const T& value);
    Stack(const Stack& other);
    ~Stack();

    void Pop();
    void Push(const T& data);
    int GetSize() const;
    bool IsEmpty() const;
    T& GetTop();
};