#include <iostream>
#include "BSTree.h"

int main()
{
	BSTree tree;
    BSTree* root;
	root = tree.insert(root, 52);
	root = tree.insert(root, 75);
	root = tree.insert(root, 59);
	root = tree.insert(root, 50);
    tree.PreOrder (root);
    tree.PostOrder (root);
    tree.InOrder (root);
    return 0;
}

