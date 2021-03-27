#include <iostream>
#include <string>
#include "BinSTree.h"

template <class T>
BinSTree<T>::BinSTree()
    :m_root(nullptr) {}

template <class T>
BinSTree<T>::BinSTree(T* arr, int size)
    :m_root(nullptr) {

}

template <class T>
BinSTree<T>::BinSTree(BinSTree& other)
    :m_root(nullptr) {
    if(other.m_root)
    {
        TreeCopyRecursive(other.m_root, m_root);
    }
}

template <class T>
BinSTree<T>::~BinSTree()
{
    TreeDeleteRecursive(m_root);
}

template <class T>
void BinSTree<T>::InsertRecursive(Node*& node, const T& data)
{
    if(node->data > data)
    {
        if(node->left) {
            InsertRecursive(node->left, data);
        }
        else
        {
            node->left = new Node(data);
        }
    }
    else
    {
        if(node->right) {
            InsertRecursive(node->right, data);
        }
        else
        {
            node->right = new Node(data);
        }
    }
}

template <class T>
void BinSTree<T>::Insert(const T& data)
{
    if(!m_root) {
        m_root = new Node(data);
        return;
    }
    InsertRecursive(m_root, data);
}

template <class T>
void BinSTree<T>::Print(const std::string type, Node*& node)
{   
    if(type == "preorder")
    {
        if(node)
        {
            std::cout << node->data << " ";
            Print(type, node->left);
            Print(type, node->right);
        }
    }
    else if(type == "inorder")
    {
        if(node)
        {
            Print(type, node->left);
            std::cout << node->data << " ";
            Print(type, node->right);
        }
    }
    else if(type == "postorder")
    {
        if(node)
        {
            Print(type, node->left);
            Print(type, node->right);
            std::cout << node->data << " ";
        }
    }
}

template <class T>
void BinSTree<T>::PrintPreorder()
{
    Print("preorder", m_root);
}

template <class T>
void BinSTree<T>::PrintInorder()
{
    Print("inorder", m_root);
}

template <class T>
void BinSTree<T>::PrintPostorder()
{
    Print("postorder", m_root);
}

template <class T>
void BinSTree<T>::TreeCopyRecursive(Node*& other_node, Node*& my_node)
{
    if(other_node && !my_node)
    {
        my_node = new Node(other_node->data);
    }
    if(other_node)
    {
        if(other_node->left)
        {
            my_node->left = new Node(other_node->left->data);
            TreeCopyRecursive(other_node->left, my_node->left);
        }
        if(other_node->right)
        {
            my_node->right = new Node(other_node->right->data);
            TreeCopyRecursive(other_node->right, my_node->right);
        }
    }
}

template <class T>
void BinSTree<T>::TreeDeleteRecursive(Node*& node)
{
    if(node)
    {
        TreeDeleteRecursive(node->left);
        TreeDeleteRecursive(node->right);
        delete node;
    }
}

template <class T>
BinSTree<T>& BinSTree<T>::operator=(BinSTree& other) {
    if(this == &other)
        return *this;
    TreeDeleteRecursive(m_root);
    m_root = nullptr;
    TreeCopyRecursive(other.m_root, m_root);
    return *this;
}


int main()
{
    BinSTree<int> a;
    a.Insert(1);
    a.Insert(7);
    a.Insert(1);
    a.Insert(5);
    a.Insert(2);
    a.Insert(4);
    BinSTree<int> b;
    b = a;
    b.PrintInorder();
}