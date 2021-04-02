#pragma once
#include <iostream>

class Tree{
	class Node{
	public:
		Node* left;
		Node* right;
		int value;
		Node(const int& value){
			this->value=value;
			left=nullptr;
			right=nullptr;
		}
	};
private:
	int* Sort(int*&,int);
	void PreOrder(Node*);
public:
	Node* m_root;
	Tree();
	Tree(int);
	Tree(int* arr,int size);
	void Print();
	void Insert(int);
	Node* Insert(Node*,int);
};
