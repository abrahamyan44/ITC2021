#include <iostream>
#include "Tree.hpp"

//creates a empty binary search tree
template <typename T>
Tree<T>::Tree()
    :root()
{
}

//creates a binary search tree and
//keep left and right nodes
template <typename T>
Tree<T>::Tree(int* array, int size)
{
    std::cout << "In constructor.\n";
    ConvertArrayToBST(root, array, 0, size);
    std::cout << "In constructor.\n";
}

//deletes left and right subnodes
template <typename T>
Tree<T>::~Tree()
{
    std::cout << "In destructor\n";
    //delete m_left;
    //delete m_right;
}

//converts sorted array to binary search tree
template <typename T>
void Tree<T>::ConvertArrayToBST(Node<T>* node, int* array, int start, int end)
{
    if (start > end)
        return;
    int middle = start + (end - start) / 2;
    node = new Node<T>(array[middle]);
    ConvertArrayToBST(node->m_left, array, start, middle - 1);
    ConvertArrayToBST(node->m_left, array, middle + 1, end);
}

//inserts value in binary search tree
template <typename T>
void Tree<T>::InsertHelper(Node<T>* node, int value)
{
    if (value > node->m_data)
    {
        if (node->m_right)    //inserts in a right hand position
        {
            InsertHelper(node->m_right, value);
        }
        else
        {
            node->m_right = new Node<T>(value); //creates new node
        }
    }
    else
    {
        if (node->m_left)     //inserts in the left hand position
        {
            InsertHelper(node->m_left, value);
        }
        else
        {
            node->m_left = new Node<T>(value);  //creates new node
        }
    }
}

template <typename T>
void Tree<T>::Insert(int value)
{
    InsertHelper(root, value);
}

template <typename T>
void Tree<T>::PreorderHelper(Node<T>* node)
{ 
    if (NULL != node)
    {
        //prints a node data
        std::cout << node->m_data  << " "; 
        //prints left node
        PreorderHelper(node->m_left);
        //prints right node
        PreorderHelper(node->m_right);
    }
}

template <typename T>
void Tree<T>::Preorder()
{
    PreorderHelper(root);
}

template <typename T>
void Tree<T>::InorderHelper(Node<T>* node)
{
    std::cout << "InorderHelper\n";
    if (NULL != node)
    {
        std::cout << "InorderHelper\n";
        //prints left node
        InorderHelper(node->m_left);
        //prints a node data
        std::cout << node->m_data  << " "; 
        //prints right node
        InorderHelper(node->m_right);
    }
    std::cout << "InorderHelper\n";
}

template <typename T>
void Tree<T>::Inorder()
{
    std::cout << "Inorder\n";
    InorderHelper(root);
    std::cout << "Inorder\n";
}

template<typename T>
void Tree<T>::PostorderHelper(Node<T>* root)
{
    if (NULL != root)
    {
        //prints left node
        PostorderHelper(root->m_left);
        //prints right node
        PostorderHelper(root->m_right);
        //prints a node data
        std::cout << root->m_data  << " "; 
    }
}

template<typename T>
void Tree<T>::Postorder()
{
    PostorderHelper(root);
}

template class Tree<int>;
