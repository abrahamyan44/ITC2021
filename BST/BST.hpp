#include <iostream>

class BST
{
private:
   struct node 
   {
       int data;
       node* left;
       node* right;
   };

private:
    node* root;
    void AddLeaf(int value, node* ptr);
    node* CreateNewNode(int data);
    node* MakeTreeFromArray(int arr[], int start, int end);
    void InOrder(node* ptr);
    void PreOrder(node* ptr);
    void PostOrder(node* ptr);

public:
    BST(); 
    BST(int arr[], int size);
    void Insert(int value);
    void Print();
};