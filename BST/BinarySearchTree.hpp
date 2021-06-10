#include <iostream>
#include <cassert>

<<<<<<< HEAD:BST/BinarySearchTree.hpp
struct node 
{
    int data;
    node* left;
    node* right;
};

class BinarySearchTree
{
private:
=======
 struct node 
   {
       int data;
       node* left;
       node* right;
   };

class BST
{
  private:
>>>>>>> 6c8ab949f0cd7d7f2cb0d05be5e6c9d265ee2ce8:BST/BST.hpp
    node* root;

    void AddLeaf(int value, node* ptr);
    node* CreateNewNode(int data);
    node* MakeTreeFromArray(int arr[], int start, int end);
    void InOrder(node* ptr);
    void PreOrder(node* ptr);
    void PostOrder(node* ptr);

void SortArray(int* arr, int n);
void SwapTwoElements(int *x, int *y);
public:
    BinarySearchTree(); 
    BinarySearchTree(int arr[], int size);
    void Insert(int value);
    void Print();
};
