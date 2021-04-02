#include <iostream>

template<typename T>
class Node{
public:
    Node<T>* left;
    Node<T>* right;
    T value;
    Node(const T& value){
        this->value=value;
        left=nullptr;
        right=nullptr;
    }
};

//nlr
template<typename T>
void PreOrder(Node<T>* root){
	if (root == nullptr)
		return;
	std::cout<<root->value<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

//lrn
template<typename T>
void PostOrder(Node<T>* root){
	if (root == nullptr)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	std::cout<<root->value<<" ";
}

//lnr
template<typename T>
void InOrder(Node<T>* root){
	if (root == nullptr)
		return;
	PostOrder(root->left);
	std::cout<<root->value<<" ";
	PostOrder(root->right);
	
}















