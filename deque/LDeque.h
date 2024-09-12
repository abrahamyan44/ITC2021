#pragma once
#include <cassert>

#include "Node.h"
#include "deque.h"

template <class T>
class LDeque : public Deque<T>
{
public:
	LDeque();
	~LDeque();

	virtual void pop_front();
	virtual void pop_back();
	virtual void push_front(const T&);
	virtual void push_back(const T&);
	virtual void erase();

	virtual const T& front();
	virtual const T& back();

	virtual bool empty() const;
	virtual int size() const ;

private:
	Node<T>* m_rear;
	Node<T>* m_front;
	int m_size;
};

template <class T>
LDeque<T>::LDeque()
	:m_rear(nullptr)
	, m_front(nullptr)
	, m_size(0)
{}

template <class T>
LDeque<T>::~LDeque()
{
	erase();
}

template<class T>
void LDeque<T>::pop_front() {
	assert(!empty());
	if (m_front == m_rear)
	{
		delete m_front;
		m_front = m_rear = nullptr;
	}
	else
	{
		m_front = m_front->prev;
		delete m_front->next;
		m_front->next = nullptr;
	}
	--m_size;
}

template<class T>
void LDeque<T>::pop_back() {
	assert(!empty());
	if (m_front == m_rear)
	{
		delete m_rear;
		m_rear = m_front = nullptr;
	}
	else
	{
		m_rear = m_rear->next;
		delete m_rear->prev;
		m_rear->prev = nullptr;
	}
	--m_size;

}

template<class T>
void LDeque<T>::push_front(const T& data) {
	Node<T>* temp = new Node<T>(data);
	if (empty()) {
		m_front = m_rear = temp;
	}
	else
	{
		m_front->next = temp;
		temp->prev = m_front;
		m_front = temp;
	}
	++m_size;
}

template<class T>
void LDeque<T>::push_back(const T& data) {
	Node<T>* temp = new Node<T>(data);
	if (empty()) {
		m_rear = m_front = temp;
	}
	else
	{
		m_rear->prev = temp;
		temp->next = m_rear;
		m_rear = temp;
	}
	++m_size;
}
template<class T>
bool  LDeque<T>::empty() const {
	return m_front == nullptr;
}
template <class T>
int LDeque<T>::size() const {
	return m_size;
}

template <class T>
void LDeque<T>::erase()  {
	while (!empty())
	{
		pop_front();
	}
}

template<class T>
 const T& LDeque<T>::front()
{
	 assert(!empty());
	 return m_front->data;
}

 template<class T>
 const T& LDeque<T>::back()
 {
	 assert(!empty());
	 return m_rear->data;
 }



