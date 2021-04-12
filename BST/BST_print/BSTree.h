#ifndef BSTREE_H
#define BSTREE_H

class BinarySearchNode
{
public:
        int m_data;
        BinarySearchNode* m_left;
        BinarySearchNode* m_right;
public:
        BinarySearchNode();
        BinarySearchNode(int value);
};

class BinarySearchTree
{
private:
        BinarySearchNode* m_root;
        void DestructorHelper (BinarySearchNode* root);
public:
        BinarySearchNode* Insert (BinarySearchNode* root, int value);
        void PreOrder (BinarySearchNode* root);
        void InOrder (BinarySearchNode* root);
        void PostOrder (BinarySearchNode* root);
        BinarySearchTree();
        ~BinarySearchTree();

};


#endif
