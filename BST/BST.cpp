#include <iostream>
#include "BST.hpp"

BST::BST()
{
    root = NULL;
}

void SwapTwoElements(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SortArray(int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                SwapTwoElements(&arr[j], &arr[j+1]);
            }
        }
    }
}

BST::node* BST::CreateNewNode(int data)
{
    node* tree_node = new node;
    tree_node->data = data;
    tree_node->left = NULL;
    tree_node->right = NULL;

    return tree_node;
}

BST::node* BST::MakeTreeFromArray(int arr[], int start, int end)
{
    if(start > end) {
        return NULL;
    } 

    int mid_index = (start + end)/2;
    root = CreateNewNode(arr[mid_index]);

    root->left = MakeTreeFromArray(arr, start, mid_index -1);

    root->right = MakeTreeFromArray(arr, mid_index + 1, end);
}

BST::BST(int arr[], int size)
{
    SortArray(arr, size);
    int start_index = 0;
    MakeTreeFromArray(arr, start_index, size);
}

void BST::AddLeaf(int value, node* ptr)
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

void BST::Insert(int value)
{
    AddLeaf(value, root);
}

void BST::InOrder(node* ptr)
{
    if(ptr == NULL) {
        return;
    }
    InOrder(ptr->left);
    std::cout << ptr->data << " " << std::endl;
    InOrder(ptr->right);
}

void BST::PreOrder(node* ptr)
{
    if(ptr == NULL) {
        return;
    } 
    std::cout << ptr->data << " " << std::endl;
    PreOrder(ptr->left);
    PreOrder(ptr->right);
}

void BST::PostOrder(node* ptr)
{
    if(ptr == NULL) {
        return;
    }
    PostOrder(ptr->left);
    PostOrder(ptr->right); 
    std::cout << ptr->data << " " << std::endl;
}

void BST::Print()
{
    InOrder(root);
    //PreOrder(root);
    //PostOrder(root);
    std::cout << "The tree is printed." << std::endl;
}