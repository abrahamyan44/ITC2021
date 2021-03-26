#ifndef LIST_H
#define LIST_HPP
#include "node.h"
#include <iostream>
template <class T>

class List {

private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* findVal(const T& n);//return node of the given number
public:
	List();
	List(const T& value);//constructor with given value
	~List();
	int size() const;//returns number of nodes that the list has
	void insertFront(const T& value);//add element to the top
	void insertBack(const T& value);// add element at the end 
	void erase(const T& value);//removes the element
	List(const List<T>& another_list);//copy constructor
	//List& operator=(const List<T>& another_list);
	void print() const;
};

template class List<int>;


#endif