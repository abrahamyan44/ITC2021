#include <iostream>
#include "BSTree.h"

BinarySearchNode::BinarySearchNode()
    :m_left (nullptr),
    m_right (nullptr) {}

BinarySearchNode::BinarySearchNode (int value)
    :m_data (value),
    m_left (nullptr),
    m_right (nullptr) {}

BinarySearchTree::BinarySearchTree() : m_root (nullptr) {}

BinarySearchTree::~BinarySearchTree()
{
    if (m_root != nullptr) {
        DestructorHelper (m_root);
    }
}

void BinarySearchTree::DestructorHelper (BinarySearchNode* root) {
    if (root->m_left) {
         DestructorHelper (root->m_left);
    } if (m_root->m_right) {
         DestructorHelper (root->m_right);
    } delete root;
}

BinarySearchNode* BinarySearchTree::Insert (BinarySearchNode* root, int value)
{
    if (root == nullptr) {
        root = new BinarySearchNode (value);
        return root;
    } if (value <= root->m_data) {
        root->m_left = Insert (root->m_left, value);
    } else {
        root->m_right = Insert (root->m_right, value);
    } return root;
}

void BinarySearchTree::PreOrder (BinarySearchNode* root)
{
    if (root != nullptr) {
        std::cout << root->m_data << " ";
        if (root->m_left) {
            PreOrder (root->m_left);
        } if (root->m_right) {
            PreOrder (root->m_right);
        }
    }
}

void BinarySearchTree::PostOrder (BinarySearchNode* root)
{
    if (root != nullptr) {
        if (root->m_left) {
            PostOrder (root->m_left);
        } if (root->m_right) {
            PostOrder (root->m_right);
        } std::cout << root->m_data << " ";
    }
}

void BinarySearchTree::InOrder (BinarySearchNode* root)
{
    if (root != nullptr) {
        if (root->m_left) {
            InOrder (root->m_left);
        } std::cout << root->m_data << " ";
        if (root->m_right) {
            InOrder (root->m_right);
        }
    }
}


