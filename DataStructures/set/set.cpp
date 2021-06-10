#include <iostream>
#include "set.h"

template <class T>
void Set<T>::InsertRecursive(Node*& node, const T& data)
{
    if(node->data == data)
    {
        return;
    }
    if(node->data > data) 
    {
        if(node->left) 
        {
            InsertRecursive(node->left, data);
        }
        else
        {
            node->left = new Set<T>::Node(data);
        }
    }
    else {
        if(node->right)
        {
            InsertRecursive(node->right, data);
        }
        else
        {
            node->right = new Set<T>::Node(data);
        }
    }
}

template <class T>
struct Set<T>::Node* Set<T>::FindRecursive(Node*& node, const T& data)
{
    if(node->data == data) {
        return node;
    }
    if(node->data > data)
    {
        if(node->left) 
        {
            return FindRecursive(node->left, data);
        }
        else
        {
            return nullptr;
        }
    }
    else 
    {
        if(node->right) 
        {
            return FindRecursive(node->right, data);
        }
        else
        {
            return nullptr;
        }
    }
}

template <class T>
Set<T>::Set(const Set<T>& other) 
{

}

template <class T>
Set<T>::~Set() {

}

template <class T>
void Set<T>::Insert(const T& data) 
{
    if(!m_root) 
    {
        m_root = new Node(data);
        return;
    }
    InsertRecursive(m_root, data);
}

template <class T>
void Set<T>::Remove(const T& data) 
{

}

template <class T>
bool Set<T>::Find(const T& data)
{
    return FindRecursive(m_root, data);
}


int main() 
{
    Set<int> a;
    a.Insert(1);
    a.Insert(3);
    a.Insert(5);
    std::cout << a.Find(4) << " ";
    return 0;
}