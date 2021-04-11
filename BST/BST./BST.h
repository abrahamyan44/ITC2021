#ifndef BST_H
#define BST_H

#include <iostream>
#include "BSN.h"

class BinarySearchTree
{
private:
    BinarySearchNode* m_root;
    void InOrder (BinarySearchNode* root);
    BinarySearchNode* PushNodeHelper (BinarySearchNode* root, int* array, int start, int end);
    BinarySearchNode* SearchNode (BinarySearchNode* root, int value);
    BinarySearchNode* Insert (BinarySearchNode* root, int value);
    BinarySearchNode* SearchNextNode (BinarySearchNode* root, int value);
    void DestructorHelper (BinarySearchNode* root);
    BinarySearchNode* SearchNodeParent (BinarySearchNode* root, int value);
    void RemoveRightNode (BinarySearchNode* node, BinarySearchNode* pnode);
    void RemoveNoChildeNode (BinarySearchNode* node, BinarySearchNode* pnode);
    void RemoveLeftNode (BinarySearchNode* node, BinarySearchNode* pnode);
    void RemoveTwoChildNode (BinarySearchNode* node,const int& value);
    void RemoveCaseForRoot (const int& value);
public:
    BinarySearchTree();
    BinarySearchTree (int* array, int size);
    void Print();
    void Insert (int value);
    void Remove (int value);
};

#endif
