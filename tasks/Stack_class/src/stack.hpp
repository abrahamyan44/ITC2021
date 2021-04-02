#pragma once
#include <iostream>


template <typename T>
class Stack{
	int m_size;
	template<typename U>
	class Node{
	public:
		int data;
		Node<U>* prev;
		Node(const U& a)
			:data(a)
			,prev(nullptr)
		{}

	};
public:
	Node<T>* m_top;
	void push(const T& data);
	void pop();
	bool empty() const;
	void print() const;
	T& top();
	int size() const;
	Stack();
	Stack(int n,const T& val);
	Stack(const Stack& other);
	~Stack();
};
