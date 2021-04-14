#include <iostream>
#include <queue>
#include <stack>
#include "TreeTraversals.hpp"
using namespace std;

template <class T>
Tree <T>::Tree () : m_root(0)
{}

template <class T>
node <T>* Tree <T>::CreateNode (T data)
{
    node <T>* node1 = new node <T>;
    node1->data = data;
    node1->left = node1->right = 0;
    return node1;
}

template <class T>
Tree <T>::~Tree ()
{
    std::cout << "Destructed!" << std::endl;
    MakeEmpty(m_root);
}

template <class T>
void Tree <T>::MakeEmpty (node <T>* leaf)
{
    if (leaf != 0) {   
        MakeEmpty(leaf->left);
        MakeEmpty(leaf->right);
        delete leaf;
    }
}

template <class T>
void Tree <T>::InOrderRecursively (node <T>* root)
{
    if (root != 0) {
        InOrderRecursively(root->left);
        std::cout << root->data << " ";
        InOrderRecursively(root->right);
    }
}

template <class T>
void Tree <T>::PreOrderRecursively (node <T>* root)
{
    if (root != 0) {
        std::cout << root->data << " ";
        PreOrderRecursively(root->left);
        PreOrderRecursively(root->right);
    }
}

template <class T>
void Tree <T>::PostOrderRecursively (node <T>* root)
{
    if (root != 0) {
        PostOrderRecursively(root->left);
        PostOrderRecursively(root->right);
        std::cout << root->data << " ";
    }
}

template <class T>
void Tree <T>::InOrder (node <T>* root)
{
    stack <node <T>*> stack1;
    node <T>* temporal = root;
    while (temporal != 0 || stack1.empty() != true) {
        while (temporal != 0) {
            stack1.push(temporal);
            temporal = temporal->left;
        }
        temporal = stack1.top();
        stack1.pop();
        std::cout << temporal->data << " ";
        temporal = temporal->right;
    }
}

template <class T>
void Tree <T>::Print (node <T>* root)
{
    queue <node <T>*> queue1, queue2;
	node <T>* pointer = root;
	if (pointer) {
		queue1.push(root);
    }
	while (1) {
		while (!queue1.empty()) {
			pointer = queue1.front();
            std::cout << pointer->data << " ";
			queue1.pop();
			if (pointer->left) {
				queue2.push(pointer->left);
            }
			if (pointer->right) {
				queue2.push(pointer->right);
            }
		}
        std::cout << std::endl;
		if (queue2.empty()) {
	            return;
        }
		while (!queue2.empty()) {
                    queue1.push(queue2.front());
                    queue2.pop();
		}
	}
}

int main()
{
    Tree <int> tree;
    node <int>* root = tree.CreateNode(4);
	root->left = tree.CreateNode(5);
	root->right = tree.CreateNode(6);
	root->left->left = tree.CreateNode(2);
	root->left->right = tree.CreateNode(3);

    std::cout << "InOrder: ";
    tree.InOrderRecursively(root);
    std::cout << std::endl;

    std::cout << "PreOrder: ";
    tree.PreOrderRecursively(root);
    std::cout << std::endl;

    std::cout << "PostOrder: ";
    tree.PostOrderRecursively(root);
    std::cout << std::endl;

    std::cout << "Iterative InOrder traversaled tree: ";
    tree.InOrder(root);
    std::cout << std::endl;

    std::cout << "Printing the tree level by level: " << std::endl;
    tree.Print(root);
    std::cout << std::endl;

    return 0;
}
