#include <iostream>
#include "BSTree.h"

int main()
{
    /*int t;
    int data;
    std::cin >> t;
    BinarySearchTree tree;
    BinarySearchNode* root = nullptr;
    while (t-- > 0) {
        std::cin >> data;
        root = tree.insert (root, data);
    }*/
	
    BinarySearchTree tree;
    BinarySearchNode* root = nullptr;
    root = tree.Insert (root, 52);
    root = tree.Insert (root, 75);
    root = tree.Insert (root, 59);
    root = tree.Insert (root, 50);
    tree.PreOrder (root);
    tree.PostOrder (root);
    tree.InOrder (root);
    return 0;
}

