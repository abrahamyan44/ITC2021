#ifndef BST_HPP
#define BST_HPP
#include <iostream>
struct Node {
		int value;
		Node* left;
		Node* right;
};

class BST {

private:

		Node* root;
		Node* insert_node(int value, Node* node);
		void preOrder(Node* root);//nlr traversal
		void inOrder(Node* root);//lnr traversal
		void postOrder(Node* root);//lrn traversal
public:

		BST(const int* data, const int size);//fill constructor
		void print_preOrder();
		void print_inOrder();
		void print_postOrder();
		void insert(int value);
		void remove(int value);

};

#endif // 

