#include "node.h"
#include "iterator.h"


Iterator::Iterator()
    :iterator (nullptr) {}

Iterator::Iterator (Node* node)
    :iterator (node) {}

Iterator::Iterator (const Iterator& itr)
    :iterator (itr.iterator) {}

void Iterator::Next() {
	if (iterator == nullptr) {
		return;
	} else {
		iterator =  iterator->m_next;
	}
}

void Iterator::Prev() {
	if (iterator == nullptr) {
        return;
	} else {
		iterator =  iterator->m_prev;
	}
}

Iterator& Iterator::operator++() {
	Next();
   	return *this;
}

Iterator Iterator::operator++ (int) {
	auto current(*this);
	operator++();
	return current;
}

Iterator& Iterator::operator--() {	
    Prev();
    return *this;
}

Iterator Iterator::operator-- (int) {
	auto temp (*this);
	operator-- ();
	return temp;
} 

bool Iterator::operator== (const Iterator& itr) {
	return iterator == itr.iterator;
} 

bool Iterator::operator!= (const Iterator& itr) {
	return iterator != itr.iterator;
} 

int& Iterator::operator*() {
	return iterator->m_data;
}

Iterator& Iterator::operator->() {
	return *this;
}
