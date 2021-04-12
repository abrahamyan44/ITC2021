
#include "BST.h"
#include <algorithm>


BinarySearchTree::BinarySearchTree()
	:m_root (nullptr) {}

BinarySearchNode* BinarySearchTree::PushNodeHelper (BinarySearchNode* root, int* array, int start, int end)
{
    if (start <= end) {
        int m = (start + end) / 2;
        root = new BinarySearchNode (array[m]);
        root->m_right = PushNodeHelper (root->m_right, array, m + 1, end);
        root->m_left = PushNodeHelper (root->m_left, array, start, m - 1);
	}
	return root;
}

BinarySearchTree::BinarySearchTree (int* array, int size)
{
    std::sort (array, array + size);
    m_root = PushNodeHelper (m_root, array, 0, size - 1);
}

void BinarySearchTree::Print()
{
    InOrder (m_root);
}

void BinarySearchTree::InOrder (BinarySearchNode* root)
{
	if (root == nullptr) {
		std::cout << "empty tree" << std::endl;
	} else {
		if (root->m_left) {
			InOrder (root->m_left);
		} std::cout << root->m_data << " ";
		if (root->m_right) {
			InOrder (root->m_right);
		}
	}
}

void BinarySearchTree::Insert (int value)
{
	m_root = Insert (m_root, value);
}

BinarySearchNode* BinarySearchTree::Insert (BinarySearchNode* root, int value)
{
	if (root == nullptr) {
		root = new BinarySearchNode (value);
        return root;
	} if (value <= root->m_data) {
        root->m_left = Insert (root->m_left, value); 
	} root->m_right = Insert (root->m_right, value);
	return root;
}

BinarySearchNode* BinarySearchTree::SearchNode (BinarySearchNode* root, int value) 
{
	if (root == nullptr) {
		return nullptr;
	} if (value == root->m_data) {
		return root;
	} if (value < root->m_data) {
		return SearchNode (root->m_left, value);
	} if (value > root->m_data) {
		return SearchNode (root->m_right, value);
	} else {
		return nullptr;
	}
}

BinarySearchNode* BinarySearchTree::SearchNextNode (BinarySearchNode* root, int value)
{
	BinarySearchNode* node = root->m_right;
	while (node->m_left != nullptr) {
	    node = node->m_left;
	} return node;
	std::cout << "next"<< std::endl;
}

BinarySearchNode* BinarySearchTree::SearchNodeParent (BinarySearchNode* root, int value) 
{
	if ((root->m_left != nullptr && root->m_left->m_data == value) || (root->m_right != nullptr && root->m_right->m_data == value)) {
		return root;
    } if (root->m_data > value) {
	    return SearchNodeParent (root->m_left, value);
	} if (root->m_data < value) {
	    return SearchNodeParent (root->m_right, value);
	} else {
		return nullptr;
	}
}

void BinarySearchTree::RemoveNoChildeNode (BinarySearchNode* node, BinarySearchNode* pnode)
{
    if (node->m_data < pnode->m_data) {
        pnode->m_left = nullptr;
    } else {
        pnode->m_right = nullptr;
    }
    delete node;
}

void BinarySearchTree::RemoveRightNode (BinarySearchNode* node, BinarySearchNode* pnode)
{
	if (pnode->m_data < node->m_data) {
        pnode->m_right = node->m_right;
    } else {
        pnode->m_left = node->m_right;
    }
    delete node;
    node = nullptr;
}

void BinarySearchTree::RemoveLeftNode (BinarySearchNode* node, BinarySearchNode* pnode)
{
	if (node->m_data < pnode->m_data) {
        pnode->m_left = node->m_left;
    } else {
        pnode->m_left = node->m_left;
    }
	delete node;
    node = nullptr;
} 

void BinarySearchTree::RemoveCaseForRoot (const int& value)
{
    BinarySearchNode* nnode = SearchNextNode (m_root, value);
    BinarySearchNode* pnnode = SearchNodeParent (m_root, nnode->m_data);
    int tmp = nnode->m_data;
    if (nnode->m_right == nullptr) {
        RemoveNoChildeNode (nnode, pnnode);
        m_root->m_data = tmp;
    } else {
        RemoveRightNode (nnode, pnnode);
        m_root->m_data = tmp;
    }
}

void BinarySearchTree::RemoveTwoChildNode (BinarySearchNode* node, const int& value)
{
    BinarySearchNode* nnode = SearchNextNode (node, value);
    BinarySearchNode* pnnode = SearchNodeParent (nnode, nnode->m_data);
    int tmp = nnode->m_data;
    if (nnode->m_right == nullptr) {
        RemoveNoChildeNode (nnode, pnnode);
        node->m_data = tmp;
    } else {
        RemoveRightNode (nnode, pnnode);
        node->m_data = tmp;
    }
}

void BinarySearchTree::Remove (int value)
{  
    if (m_root == nullptr) {
        std::cout << "no tree" << std::endl;
	    return;
    } BinarySearchNode* node = SearchNode (m_root, value); 
    if (node == nullptr) {
        std::cout << "no such value in this tree" << std::endl;
        return;
	} if (value != m_root->m_data) {
    BinarySearchNode* pnode = SearchNodeParent (m_root, value);
    if ((node->m_left == nullptr && node->m_right == nullptr)) {
        RemoveNoChildeNode (node, pnode);
    } else if (node->m_left == nullptr && node->m_right != nullptr) { 
        RemoveRightNode (node, pnode);
    } else if (node->m_left != nullptr && node->m_right == nullptr) {
        RemoveLeftNode (node, pnode);
    } else {
        RemoveTwoChildNode (node, value);
    }
    } if (value == m_root->m_data) {
	    RemoveCaseForRoot (value);
  	} 
}

