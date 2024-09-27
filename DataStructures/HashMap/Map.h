#pragma once
#include <vector>

template <class T1, class T2>
class Map 
{
private:
    struct Node
    {
    public:
        T1 key;
        T2 data;
        Node* next;
        Node(T1 key, T2 data)
            :key(key), data(data), next(nullptr) {}
    };
    Node** arr;
    int m_size;
    static const int hashing_max_size = 2;


    void RemoveRecursive(Node* node);

public:

    Map();
    Map(const Map& other);
    ~Map();
    int HashingAlgorithm(const T1& key);
    void Insert(T1 key, T2 data);
    void Remove(T1 key);
    T2& operator[](T1 key);
    bool IsEmpty() const;
    int GetSize() const;
};