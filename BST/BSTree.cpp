#include <iostream>
#include "BSTree.h"

BSNode::BSNode()
    :m_left(nullptr),
    m_right(nullptr) {}

BSNode::BSNode (int value)
    :m_data(value),
    m_left(nullptr),
    m_right(nullptr) {}

BSTree::BSTree() : m_root(nullptr) {}

BSTree::~BSTree()
{
    if (m_root != nullptr) {
        DestructorHelper (m_root);
    }
}

void BSTree::DestructorHelper (BSNode* root) {
    if (root->m_left) {
         DestructorHelper (root->m_left);
    } if (root->m_right) {
         DestructorHelper (root->m_right);
    } delete root;
}

BSNode* BSTree::insert (BSNode* root, int value)
{
    if (root == nullptr) {
        root = new BSNode (value);
        return root;
    } if (value <= root->m_data) {
        root->m_left = insert (root->m_left, value);
    } else {
        root->m_right = insert (root->m_right, value);
    } return root;
}

void BSTree::PreOrder (BSNode* root)
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

void BSTree::PostOrder (BSNode* root)
{
    if (root != nullptr) {
        if (root->m_left) {
            PostOrder (root->m_left);
        } if (root->m_right) {
            PostOrder (root->m_right);
        } std::cout << root->m_data << " ";
    }
}

void BSTree::InOrder (BSNode* root)
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


