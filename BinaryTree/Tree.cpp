#include <iostream>
#include <cassert>
#include "Tree.hpp"

//creates a empty binary search tree
template <typename T>

Tree<T>::Tree()
    :root(nullptr)
{
}

//creates a binary search tree and
//keep left and right nodes
template <typename T>

Tree<T>::Tree(int* array, int size)
    :root(nullptr)
{
    ConvertArrayToBinarySearchTree (root, array, 0, size);
}

//deletes left and right subnodes
template <typename T>

Tree<T>::~Tree()
{
    std::cout << "In destructor\n";
    delete root;
}

//converts sorted array to binary search tree
template <typename T>

void Tree<T>::ConvertArrayToBinarySearchTree (Node<T>*& node, int* array, int start, int end)
{
    if (start > end) {
        return;
    }
    int middle = start + (end - start) / 2;
    node = new Node<T> (array[middle]);
    ConvertArrayToBinarySearchTree (node->m_left, array, start, middle - 1);
    ConvertArrayToBinarySearchTree (node->m_right, array, middle + 1, end);
}

//inserts value in binary search tree
template <typename T>

void Tree<T>::InsertFromGivenNode (Node<T>*& node, int value)
{
    if (nullptr == node) {
        node = new Node<T> (value);     //creats new node
    } else {
        if (value > node->m_data) {
            //inserts in a right hand position
            InsertFromGivenNode (node->m_right, value);
        } else {
            //inserts in the left hand position
            InsertFromGivenNode (node->m_left, value);
        }
    }
}

template <typename T>

void Tree<T>::Insert(int value)
{
    InsertFromGivenNode (root, value);
}

template <typename T>

void Tree<T>::PrintPreOrderRecursively(Node<T>* node)
{ 
    if (nullptr != node)
    {
        //prints a node data
        std::cout << node->m_data  << " "; 
        //prints left node
        PrintPreOrderRecursively(node->m_left);
        //prints right node
        PrintPreOrderRecursively(node->m_right);
    }
}

template <typename T>

void Tree<T>::PrintPreOrder()
{
    PrintPreOrderRecursively (root);
}

template <typename T>

void Tree<T>::PrintInOrderRecursively (Node<T>* node)
{
    if (nullptr != node) {
        //prints left node
        PrintInOrderRecursively (node->m_left);
        //prints a node data
        std::cout << node->m_data  << " "; 
        //prints right node
        PrintInOrderRecursively (node->m_right);
    }
}

template <typename T>

void Tree<T>::PrintInOrder()
{
    PrintInOrderRecursively (root);
}

template<typename T>

void Tree<T>::PrintPostOrderRecursively(Node<T>* root)
{
    if (nullptr != root)
    {
        //prints left node
        PrintPostOrderRecursively (root->m_left);
        //prints right node
        PrintPostOrderRecursively (root->m_right);
        //prints a node data
        std::cout << root->m_data  << " "; 
    }
}

template<typename T>

void Tree<T>::PrintPostOrder()
{
    PrintPostOrderRecursively (root);
}
