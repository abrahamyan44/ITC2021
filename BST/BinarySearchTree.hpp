#include <iostream>

struct node 
{
    int data;
    node* left;
    node* right;
};

class BinarySearchTree
{
private:
    node* root;
    void AddLeaf(int value, node* ptr);
    node* CreateNewNode(int data);
    node* MakeTreeFromArray(int arr[], int start, int end);
    void InOrder(node* ptr);
    void PreOrder(node* ptr);
    void PostOrder(node* ptr);

public:
    BinarySearchTree(); 
    BinarySearchTree(int arr[], int size);
    void Insert(int value);
    void Print();
};