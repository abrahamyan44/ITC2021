#include <iostream>
#include "stack.hpp"

template<typename T>
Stack<T>::Stack()
			:m_size(0)
			,m_top(nullptr)
{}

template<typename T>
Stack<T>::~Stack(){
	if(	empty()	){
		return;
	}
    Node<T>* cur=m_top;
    while( cur != nullptr ){
        Node<T>* temp=cur;
        cur=cur->prev;
        delete temp;
    }

}

template<typename T>
Stack<T>::Stack(const Stack& x){
	m_top=new Node<T>(x.m_top->data);
	for (Node<T>* p=x.m_top->prev; p != nullptr ; p = p->prev){
		Node<T>* current = new Node<T>(p->data);
		current->prev=m_top;
		m_top=current;
	}
}

template<typename T>
T& Stack<T>::top(){
	return m_top->data;
}

template<typename T>
Stack<T>::Stack(int n,const T& val){
	m_size=n;
	m_top=new Node<T>(val);
	for (int i = 0; i < n-1; i++){
		Node<T>* temp=new Node<T>(val);
		temp->prev=m_top;
		m_top=temp;
	}
}

template<typename T>
void Stack<T>::print() const{
	std::cout<<"[";
	for (Node<T>* p = m_top; p != nullptr;p = p->prev){
		std::cout<<p->data<<" ";
	}
	std::cout<<"]";
}

template<typename T>
bool Stack<T>::empty() const{
	if (m_top->prev == nullptr){
		return true;
	}
	return false;

}

template<typename T>
void Stack<T>::push(const T& data){
	Node<T>* temp=new Node<T>(data);
	temp->prev=m_top;
	m_top=temp;
	m_size++;
}

template<typename T>
void Stack<T>::pop(){
    Node<T>*temp=m_top;
	m_top=m_top->prev;
	delete temp;
}

template<typename T>
int Stack<T>::size() const{
	return m_size;
}










