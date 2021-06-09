#include <iostream>
#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BST::BST(int* arr, int size)
{
    root = CreateNewNode(0);
    SortArray(arr, size);
    int start_index = 0;

    std::cout << "ctor    "  <<  start_index << ' ' << size  << "     Root     " << root << std::endl;

    MakeTreeFromArray(arr, start_index, size);
}

void BST::SwapTwoElements(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BST:: SortArray(int* arr, int n)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                SwapTwoElements(&arr[j], &arr[j+1]);
            }
        }
    }
}

<<<<<<< HEAD:BST/BinarySearchTree.cpp
BinarySearchTree::node* BinarySearchTree::CreateNewNode(int data)
{
    node* tree_node = new node;
=======
node* BST::CreateNewNode(int data)
{		
    node* tree_node= new node;
    
    assert(tree_node != NULL);
    
    std::cout <<tree_node << "   tree_node   " << std::endl;
    
>>>>>>> 6c8ab949f0cd7d7f2cb0d05be5e6c9d265ee2ce8:BST/BST.cpp
    tree_node->data = data;
    tree_node->left = NULL;
    assert(tree_node->left == NULL);
   
    tree_node->right = NULL;
    assert(tree_node->right == NULL);

    std::cout <<tree_node << "   tree_node   " << std::endl;
    return tree_node;
}

<<<<<<< HEAD:BST/BinarySearchTree.cpp
BinarySearchTree::node* BinarySearchTree::MakeTreeFromArray(int arr[], int start, int end)
=======
node* BST::MakeTreeFromArray(int* arr, int start, int end)
>>>>>>> 6c8ab949f0cd7d7f2cb0d05be5e6c9d265ee2ce8:BST/BST.cpp
{
std::cout << "MAKE   "  << start << ' ' << end << std::endl;

    int mid_index = (start + end)/2;
    //assert(start < mid_index);
    if(start >= mid_index || end <= mid_index) {

    root = CreateNewNode(arr[mid_index]);
        return nullptr;
    }

    //root = CreateNewNode(arr[mid_index]);

    root->left = MakeTreeFromArray(arr, start, mid_index);

<<<<<<< HEAD:BST/BinarySearchTree.cpp
BinarySearchTree::BinarySearchTree(int arr[], int size)
{
    SortArray(arr, size);
    int start_index = 0;
    MakeTreeFromArray(arr, start_index, size);
=======
    root->right = MakeTreeFromArray(arr, mid_index + 1, end);
	
    //return 0; 
>>>>>>> 6c8ab949f0cd7d7f2cb0d05be5e6c9d265ee2ce8:BST/BST.cpp
}

void BinarySearchTree::AddLeaf(int value, node* ptr)
{
    if(root == NULL)
    {
        root = CreateNewNode(value);
    }
    else if(value < ptr->data)
    {
        if(ptr->left != NULL)
        {
            AddLeaf(value, ptr->left);
        }
        else
        {
            ptr->left = CreateNewNode(value);
        }
    }
    else if(value > ptr->data)
    {
        if(ptr->right != NULL)
        {
            AddLeaf(value, ptr->right);
        }
        else
        {
            ptr->right = CreateNewNode(value);
        }
    }
    else
    {
        std::cout << "Node with the given value exists..." << std::endl;
    }
}

void BinarySearchTree::Insert(int value)
{
    AddLeaf(value, root);
}

void BinarySearchTree::InOrder(node* ptr)
{
    assert(nullptr != ptr);

    if(ptr == NULL) {
        return;
    }
    InOrder(ptr->left);
    std::cout << ptr->data << " " << std::endl;
    InOrder(ptr->right);
}

void BinarySearchTree::PreOrder(node* ptr)
{
    assert(nullptr != ptr);
    if(ptr == NULL) {
        return;
    } 
    std::cout << ptr->data << " " << std::endl;
    PreOrder(ptr->left);
    PreOrder(ptr->right);
}

void BinarySearchTree::PostOrder(node* ptr)
{

    assert(nullptr != ptr);
    if(ptr == NULL) {
        return;
    }
    PostOrder(ptr->left);
    PostOrder(ptr->right); 
    std::cout << ptr->data << " " << std::endl;
}

void BinarySearchTree::Print()
{
    //InOrder(root);
    PreOrder(root);
    //PostOrder(root);
    std::cout << "The tree is printed." << std::endl;
}
