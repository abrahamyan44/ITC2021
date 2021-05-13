#include <iostream>
#include <cassert>

 struct node 
   {
       int data;
       node* left;
       node* right;
   };

class BST
{
  private:
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
    BST(); 
    BST(int arr[], int size);
    void Insert(int value);
    void Print();
};
