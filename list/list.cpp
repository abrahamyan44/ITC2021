#include "list.hpp"
#include "node.h"

template <class T>
List<T>::List()
	:head(nullptr),
	tail(nullptr)
{
	std::cout << "Default constructor for List class called!" << std::endl;
}

template <class T>
List<T>::~List()
{

	Node<T>* current = nullptr;
	while (head) {
		current = head;
		head = head->next;
		delete current;
	}
	std::cout << "Destructor for class List called!" << std::endl;
}

template <class T>
void List<T>::insertFront(const T& value)
{
	Node<T>* node = new Node<T>(value);
	Node<T>* tmp = head;
	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->next = head;
		head = node;
		node->next->prev = node;
	}
}

template <class T>
void List<T>::erase(const T& value)
{
	Node<T>* find = findVal(value);
	if (head == nullptr || find == nullptr)
		return;
	if (head == find)
		head = find->next;
	if (find->next != nullptr)
		find->next->prev = find->next;
	delete find;
	return;
}

template <class T>
void List<T>::insertBack(const T& value)
{
	Node<T>* node = new Node<T>(value);
	if (tail == nullptr)
	{
		head = tail = node;
		node->next = node->prev = nullptr;
	}
	else if (tail->next == nullptr)
	{
		tail->next = node;
		tail = node;
	}
}

template <class T>
Node<T>* List<T>::findVal(const T& n)
{
	Node<T>* node = head;
	while (node != nullptr)
	{
		if (node->value == n)
		{
			return node;
		}
		node = node->next;
	}
	std::cerr << "No such element in the list" << std::endl;
	return nullptr;
}

template <class T>
int List<T>::size()const 
{
	int size = 0;
	Node<T>* current = head;

	while (current != NULL) {
		Node<T>* temp = current->next;
		size++;
		current = temp;
	}
	return size;
}

template <class T>
void List<T>::print()const
{
	Node<T>* n = new Node<T>();
		n = head;
	std::cout << "[";
	do {
		std::cout << " " << n->value;
		n = n->next;
	} while (n != nullptr);
	std::cout << "]" << std::endl;

}

