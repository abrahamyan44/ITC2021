#include <iostream>
#include <queue>
#include <stack>
#include "TreeTraversals.hpp"
using namespace std;

template <class T>
Tree <T>::Tree() : m_root(0)
{}

template <class T>
Node <T>* Tree <T>::CreateNode(T data)
{
    Node <T>* node = new Node <T>;
    node->data = data;
    node->left = node->right = 0;
    return node;
}

template <class T>
Tree <T>::~Tree()
{
    std::cout << "Destructed!" << std::endl;
    MakeEmpty(m_root);
}

template <class T>
void Tree <T>::MakeEmpty(Node <T>* leaf)
{
    if (leaf != 0) {   
        MakeEmpty(leaf->left);
        MakeEmpty(leaf->right);
        delete leaf;
    }
}

template <class T>
void Tree <T>::InOrderRecursively(Node <T>* root)
{
    if (root != 0) {
        InOrderRecursively(root->left);
        std::cout << root->data << " ";
        InOrderRecursively(root->right);
    }
}

template <class T>
void Tree <T>::PreOrderRecursively(Node <T>* root)
{
    if (root != 0) {
        std::cout << root->data << " ";
        PreOrderRecursively(root->left);
        PreOrderRecursively(root->right);
    }
}

template <class T>
void Tree <T>::PostOrderRecursively(Node <T>* root)
{
    if (root != 0) {
        PostOrderRecursively(root->left);
        PostOrderRecursively(root->right);
        std::cout << root->data << " ";
    }
}

template <class T>
void Tree <T>::InOrder(Node <T>* root)
{
    stack <Node <T>*> stack1;
    Node <T>* temp = root;
    while (temp != 0 || stack1.empty() != true) {
        while (temp != 0) {
            stack1.push(temp);
            temp = temp->left;
        }
        temp = stack1.top();
        stack1.pop();
        std::cout << temp->data << " ";
        temp = temp->right;
    }
}

template <class T>
void Tree <T>::Print(Node <T>* root)
{
    queue <Node <T>*> queue1, queue2;
	Node <T>* ptr = root;
	if (ptr) {
		queue1.push(root);
    }
	while (1) {
		while (!queue1.empty()) {
			ptr = queue1.front();
            std::cout << ptr->data << " ";
			queue1.pop();
			if (ptr->left) {
				queue2.push(ptr->left);
            }
			if (ptr->right) {
				queue2.push(ptr->right);
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
    Node <int>* root = tree.CreateNode(4);
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
