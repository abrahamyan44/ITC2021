#include <iostream>
#include <vector>
#include "Map.h"

template <class T1, class T2>
Map<T1, T2>::Map()
{
    arr = new Node*[hashing_max_size];
    for(int i = 0; i < hashing_max_size; ++i)
    {
        arr[i] = nullptr;
    }
    m_size = 0;
}


template <class T1, class T2>
Map<T1, T2>::Map(const Map<T1, T2>& other)
{
    arr = new Node*[hashing_max_size];
    m_size = 0;
    for(int i = 0; i < hashing_max_size; ++i)
    {
        arr[i] = nullptr;
    }
    for(int i = 0; i < hashing_max_size; ++i)
    {
        Node* node = other.arr[i];
        while(node)
        {
            Insert(node->key, node->data);
            node = node->next;
        }
    }
}


template <class T1, class T2>
Map<T1, T2>::~Map()
{
    for(int i = 0; i < hashing_max_size; ++i)
    {
        Node* node = arr[i];
        RemoveRecursive(node);
    }
    delete[] arr;
}


template <class T1, class T2>
int Map<T1, T2>::HashingAlgorithm(const T1& key)
{
    return int(key) % hashing_max_size;
}


template <class T1, class T2>
void Map<T1, T2>::Insert(T1 key, T2 data)
{
    int index = HashingAlgorithm(key);
    Node* q = new Node(key, data);
    if(arr[index])
    {
        Node* node = arr[index];
        while(node->next)
        {
            node = node->next;
        }
        node->next = q;
    }
    else
    {
        arr[index] = q;
    }
    ++m_size;
}


template <class T1, class T2>
void Map<T1, T2>::Remove(T1 key)
{
    int index = HashingAlgorithm(key);
    if(arr[index])
    {
        if(arr[index]->key == key)
        {
            arr[index] = arr[index]->next;
            --m_size;
        }
        else
        {
            Node* node = arr[index];
            while(node->next)
            {
                if(node->next->key == key)
                {
                    Node* q = node->next;
                    node->next = q->next;
                    delete q;
                    --m_size;
                    break;
                }
                node = node->next;
            }
        }
    }
}


template <class T1, class T2>
T2& Map<T1, T2>::operator[](T1 key)
{
    int index = HashingAlgorithm(key);
    Node* node = arr[index];
    while(node)
    {
        if(node->key == key)
        {
            return node->data;
        }
        node = node->next;
    }
    throw "No data with given key";
}


template <class T1, class T2>
bool Map<T1, T2>::IsEmpty() const
{
    return m_size == 0;
}


template <class T1, class T2>
int Map<T1, T2>::GetSize() const
{
    return m_size;
}


template <class T1, class T2>
void Map<T1, T2>::RemoveRecursive(Node* node)
{
    if(!node)
    {
        return;
    }
    if(!node->next)
    {
        delete node;
        return;
    }
    if(!(node->next)->next)
    {
        Node* q = node->next;
        delete q;
        delete node;
        return;
    }
    RemoveRecursive(node->next);
}


int main()
{
    Map<int, int> a;
    a.Insert(1, 25);
    a.Insert(1 + 100, 45);
    a.Insert(1 + 200, 105);
    a.Remove(101);
    a.Remove(101);
    try {
        std::cout << a[201] << " ";
    } catch(const char* A) { 
        std::cout << A << std::endl; 
    }
    try {
        std::cout << a[101] << " ";
    } catch(const char* A) { 
        std::cout << A << std::endl; 
    }
    Map<int, int> b(a);
    std::cout << b.GetSize() << std::endl;
    return 0;
}