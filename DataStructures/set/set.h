#pragma once

template <class T>
class Set
{
    struct Node
    {
        Node* right;
        Node* left;
        T data;

        Node(const T& data)
            :right(0), left(0), data(data) {}
    };

    Node* m_root;

    void InsertRecursive(Node*& node, const T& data);
    Node* FindRecursive(Node*& node, const T& data);

public:
    Set()
        :m_root(0) {}
    Set(const Set& other);
    ~Set();
    void Insert(const T& data);
    void Remove(const T& data);
    bool Find(const T& data);
};