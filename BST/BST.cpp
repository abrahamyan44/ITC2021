#include <iostream>
#include "BST.hpp"

template <class T>
BST <T>::BST() : m_root(0)
{}

template <class T>
Node <T>* BST <T>::CreateBST(T* arr, int start, int end)
{
    SortedArray(arr, end + 1);
    if(start > end) {
        return 0;
    }
    //get middle element and make it root
    int middle = (start + end) / 2;
    Node <T>* temp = new Node <T>;
    temp->data = arr[middle];
    temp->left = CreateBST(arr, start, middle-1);
    temp->right = CreateBST(arr, middle+1, end);
    return temp;
}

template <class T>
BST <T>::~BST()
{
    std::cout << "Destructed!" << std::endl;
    MakeEmpty(m_root);
}

template <class T>
void BST <T>::SortedArray(T* arr, int size)
{
    for (int i=0; i < size; i++) {
        for (int j=0; j < size-1; j++) {
            if (arr[j] > arr[i]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <class T>
void BST <T>::MakeEmpty(Node <T>* leaf)
{
    if (leaf != 0) {
        MakeEmpty(leaf->left);
        MakeEmpty(leaf->right);
        delete leaf;
    }
}

template <class T>
bool BST <T>::IsEmpty()
{
    return (m_root == 0);
}

template <class T>
void BST <T>::Insert(T value)
{
    Node <T>* temp = new Node <T>;
    Node <T>* parent = 0;
    temp->left = 0;
    temp->right = 0;
    temp->data = value;
    if (IsEmpty()) {
        m_root = temp;
    } else {
        Node <T>* ptr = m_root;
        while (ptr != 0) {
            parent = ptr;
            if (value > ptr->data) {
                ptr = ptr->right; 
            } else if (value < ptr->data) {
                ptr = ptr->left;
            } else {
                std::cout << "Object exists in the tree! " << std::endl;
            }
        }
        if (value > parent->data) {
            parent->right = temp;
        } else if (value < parent->data) {
            parent->left = temp;
        }
    }
}

template <class T>
Node <T>* BST <T>::GetRoot()
{
    return m_root;
}

template <class T>
void BST <T>::PrintInOrder(Node <T>* root)
{
    if (root != 0) {
        PrintInOrder(root->left);
        std::cout << root->data << " ";
        PrintInOrder(root->right);
    }
}

template <class T>
Node <T>* BST <T>::GetMinimumNode(Node <T>* node)
{
    Node <T>* temp = node;
    while (temp != 0 && temp->left != 0) {
        temp = temp->left;
    }
    return temp;
}

template <class T>
Node <T>* BST <T>::Remove(Node <T>* root, int value)
{
    if (root == 0) {
        return root;
    }
    if (value < root->data) {
        root->left = Remove(root->left,value);
    } else if (value > root->data) {
        root->right = Remove(root->right, value);
    } else { //Case1: No child
        if (root->left == 0 && root->right == 0) {
            delete root;
            root = 0;
        } else if (root->left == 0) { //Case2: One child(left or right)
            Node <T>* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == 0) {
                Node <T>* temp = root->left;
                delete root;
                return temp;
        } else { //Case3: 2 children
        Node <T>* temp = GetMinimumNode(root->right);
        root->data = temp->data;
        root->right = Remove(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    BST <int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);
    std::cout << "Here is the tree: ";
    tree.PrintInOrder(tree.GetRoot());
    std::cout << std::endl;
    tree.Remove(tree.GetRoot(),3);
    std::cout << "Here is the tree after removing node with 3 value: ";
    tree.PrintInOrder(tree.GetRoot());
    std::cout << std::endl;
    
    const int n = 7;
    int arr[] = {1,6,5,7,8,4,9};
    BST <int> tree1;
    Node <int>* root = tree1.CreateBST(arr, 0, n-1);
    std::cout << "Here is the BST from an array: ";
    tree1.PrintInOrder(root);
    std::cout << std::endl;

    return 0;
}

