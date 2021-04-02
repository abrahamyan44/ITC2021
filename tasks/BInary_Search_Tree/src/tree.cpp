#include <iostream>
#include "tree.hpp"



Tree::Tree(){
	m_root = nullptr;
}

Tree::Tree(int value){
	m_root = new Node(value);
}

Tree::Tree(int* array,int size){
	Sort(array,size);
	int index = (size-1)/2; 
	m_root=new Node(array[index]);
	for(int i = 0; i < size ; i++){
			Insert(array[i]);
	}
}

int* Tree::Sort(int*& a,int size){
	for (int i = 0; i < size-1; i++){
		for (int j = 0; j < size-1; j++){
			if (a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1]=temp;
			}
		}
	}
	return a;
}

Tree::Node* Tree::Insert(Node* root,int value){
	if (root == nullptr){
		root = new Node(value);
	}else if (value < root->value){
			root->left = Insert(root->left,value);
	}else if (value > root->value){
			root->right = Insert(root->right,value);
	}
	return root;
}

void Tree::PreOrder(Node* root){
    if (root == nullptr){
        return;
	}
    std::cout<<root->value<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Tree::Print(){
	PreOrder(m_root);
	std::cout << std::endl;
}

void Tree::Insert(int value){
	m_root=Insert(m_root,value);
}

















