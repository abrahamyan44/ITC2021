#include <iostream>
#include "list.h"

template <class T>
list<T>::list() 
    :size(0), first(nullptr) {}

template <class T>
list<T>::list(const list& a) 
    :size(0), first(nullptr) {
    (*this) = a;
}

template <class T>
void list<T>::push_back(T d) {
    if(empty()) {
        first = new node(d);
    }
    else {
        node* q = first;
        while(q->next) {
            q = q->next;
        }
        node* g = new node(d);
        q->next = g;
        g->prev = q;
    }
    ++size;
}

template <class T>
void list<T>::push_front(T d) {
    if(empty()) {
        first = new node(d);
    }
    else {
        node* q = new node(d);
        q->next = first;
        first->prev = q;
        first = q;
    }
    ++size;
}

template <class T>
void list<T>::pop_back() {
    if(empty()) {
        return;
    }
    node* q = first;
    if(size == 1) {
        first = nullptr;
        delete q;
    }
    else {
        while(q->next) {
            q = q->next;
        }
        (q->prev)->next = nullptr;
        delete q;
    }
    --size;
}

template <class T>
void list<T>::pop_front() {
    if(empty()) {
        return;
    }
    if(size == 1) {
        node* q = first;
        first = nullptr;
        delete q;
    }
    else {
        node* q = first;
        (first->next)->prev = nullptr;
        first = first->next;
        delete q;
    }
    --size;
}

template <class T>
void list<T>::insert(int index, T d) {
    if(index >= size) {
        push_back(d);
        return;
    }
    if(index <= 0) {
        push_front(d);
        return;
    }
    node* q = first;
    for(int i = 1; i < index; ++i) {
	q = q->next;
    }
    node* g = new node(d);
    g->prev = q;
    g->next = q->next;
    q->next = g;
    (g->next)->prev = g;
    ++size;
}

template <class T>
void list<T>::remove(int index) {
    if(empty() || index < 0 || index >= size) {
        return;
    }
    if(index == 0) {
        pop_front();
        return;
    }
    if(index == size - 1) {
        pop_back();
        return;	
    }
    node* q = first;
    for(int i = 1; i < index; ++i) {
	    q = q->next;
    }
    node* g = q->next;
    q->next = g->next;
    (g->next)->prev = q;
    --size;
    delete g;
}

template <class T>
list<T>& list<T>::operator=(const list<T>& a) {
    if(this == &a) {
        return *this;
    }
    if(!a.empty()) {
        node* q = a.first;
        while(q = q->next) {
            push_back(q->data);
            q = q->next;
        }
    }
    return *this;
}

template <class T>
bool list<T>::operator==(const list& a) const {
    if(size == a.size) {
	node* q1 = first;
	node* q2 = first;
	while(q1) {
	    if(q1->data != q2->data) {
		return false;
	    }
	    q1 = q1->next;
	    q2 = q2->next;
	}
	return true;
    }
    return false;
}

template <class T>
bool list<T>::operator!=(const list& a) const {
	return !(*this == a);
}

template <class T>
bool list<T>::empty() const {
    if(size == 0)
        return true;
    return false;    
}

template <class T>
int list<T>::get_size() const {
    return size;
}

template <class T>
void list<T>::print() const {
    node* q = first;
    while(q) {
        std::cout << q->data << " ";
        q = q->next;
    }
}

template <class T>
list<T>::~list() {
    node* q = first;
    while(q) {
        node* g = q;
        q = q->next;
        delete g;
    }
}