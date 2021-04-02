#include <iostream>
#include "tree.cpp"


int main(){
	Node<int>* root = new Node<int>(5);
	root->left = new Node<int>(15);
	root->left->left = new Node<int>(47);
	root->left->right = new Node<int>(81);
	root->right = new Node<int>(97);
	root->right = new Node<int>(1000);
	root->right->left = new Node<int>(457);
	root->right->left->left = new Node<int>(856);
	std::cout<<"1. pre-order"<<std::endl;
	PreOrder(root);
	std::cout<<std::endl;
	std::cout<<"2. post-order"<<std::endl;
	PostOrder(root);
	std::cout<<std::endl;
	std::cout<<"3. in-order"<<std::endl;
	InOrder(root);
	std::cout<<std::endl;
}
