#include <iostream>
#include <string>
#include "BinSTree.h"

template <class T>
BinSTree<T>::BinSTree()
    :m_root(nullptr) {}

template <class T>
BinSTree<T>::BinSTree(T* arr, int size)
    :m_root(nullptr) {
        for(int i = 0; i < size; ++i) 
        {
            Insert(arr[i]);
        }
}

template <class T>
BinSTree<T>::BinSTree(const BinSTree& other)
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

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BinSTree<T>::InsertRecursive(Node* node, const T& data)
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

//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BinSTree<T>::Print(const std::string type, Node* node)
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

///////////////////////////////////////////////////////////////////////////////

template <class T>
void BinSTree<T>::TreeCopyRecursive(const Node* other_node, Node* my_node)
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
            const Node* node = other_node->left;
            TreeCopyRecursive(node, my_node->left);
        }
        if(other_node->right)
        {
            my_node->right = new Node(other_node->right->data);
            const Node* node = other_node->right;
            TreeCopyRecursive(node, my_node->right);
        }
    }
}

template <class T>
BinSTree<T>& BinSTree<T>::operator=(const BinSTree& other) {
    if(this == &other)
        return *this;
    TreeDeleteRecursive(m_root);
    m_root = nullptr;
    const Node* node = other.m_root;
    TreeCopyRecursive(node, m_root);
    return *this;
}

////////////////////////////////////////////////////////////////////////////////

template <class T>
void BinSTree<T>::TreeDeleteRecursive(Node* node)
{
    if(node)
    {
        TreeDeleteRecursive(node->left);
        TreeDeleteRecursive(node->right);
        delete node;
    }
}

template <class T>
struct BinSTree<T>::Node* BinSTree<T>::FindDeletableNodesParentRecursive(Node* node, const T& data)
{
    if(node->data > data && node->left)
    {   
        if(node->left->data == data)
        {
            return node;
        }
        return FindDeletableNodesParentRecursive(node->left, data);
    }
    if(node->data < data && node->right)
    {
        if(node->right->data == data)
        {
            return node;
        }
        return FindDeletableNodesParentRecursive(node->right, data);
    }

    return nullptr;
}

template <class T>
struct BinSTree<T>::Node* BinSTree<T>::FindSubstituteNodeDataRecursive(Node* parent_node, Node* substitute_node)
{
    if(substitute_node->right)
    {
        Node* sub_node = substitute_node->right;
        return FindSubstituteNodeDataRecursive(substitute_node, sub_node);
    }
    if(parent_node->left == substitute_node)
    {
        parent_node->left = substitute_node->left;
    }
    else
    {
        parent_node->right = substitute_node->left;
    }
    
    return substitute_node;
}

template <class T>
void BinSTree<T>::GetDeletableAndParentNodes(Node* parent_node, Node* deletable_node, const T& data)
{
    if(m_root->data != data)
    {
        parent_node = FindDeletableNodesParentRecursive(m_root, data);
        if(!parent_node)
        {
            return;
        }
        if(parent_node->left && parent_node->left->data == data)
        {
            deletable_node = parent_node->left;
        }
        else
        {
            deletable_node = parent_node->right;
        }
    }
    else
    {
        parent_node = nullptr;
        deletable_node = m_root;
    }
}

template <class T>
void BinSTree<T>::GetAndReplaceSubstituteNode(Node* parent_node, Node* deletable_node)
{
    Node* substitute_node;
    if(deletable_node->left && !deletable_node->right)
    {
        substitute_node = deletable_node->left;
    }
    else if(deletable_node->right && !deletable_node->left)
    {
        substitute_node = deletable_node->right;
    }
    else if(!deletable_node->left && !deletable_node->right)
    {
        substitute_node = nullptr;
    }
    else
    {
        Node* sub_node = deletable_node->left;
        Node* substitute_node = FindSubstituteNodeDataRecursive(deletable_node, sub_node);
        substitute_node->left = deletable_node->left;
        substitute_node->right = deletable_node->right;
    }
    ReplaceSubstituteAndDeletableNodes(parent_node, deletable_node, substitute_node);
}

template <class T>
void BinSTree<T>::ReplaceSubstituteAndDeletableNodes(Node* parent_node, Node* deletable_node, Node* substitute_node)
{
    if(parent_node)
    {
        if(parent_node->left == deletable_node)
        {
            parent_node->left = substitute_node;
        }
        else
        {
            parent_node->right = substitute_node;
        }
    }
    else
    {
        m_root = substitute_node;
    }
    delete deletable_node;
}

template <class T>
void BinSTree<T>::Remove(const T& data)
{
    if(!m_root) {
        return;
    }
    Node* parent_node;
    Node* deletable_node;
    GetDeletableAndParentNodes(parent_node, deletable_node, data);
    GetAndReplaceSubstituteNode(parent_node, deletable_node);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    BinSTree<int> a;
    a.Insert(1);
    a.Insert(0);
    a.Insert(10);
    a.Insert(15);
    a.Insert(5);
    a.Insert(2);
    a.Insert(7);
    a.Insert(13);
    a.Insert(17);
    a.Insert(16);
    BinSTree<int> b;
    b = a;
    b.Remove(5);
    b.PrintPreorder();
}