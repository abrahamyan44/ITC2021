#include "node.h"
#include "iterator.h"


Iterator::Iterator()
    :iterator (nullptr) {}

Iterator::Iterator (Node* node)
    :iterator (node) {}

Iterator::Iterator (const Iterator& itr)
    :iterator (itr.iterator) {}

void Iterator::next() {
	if (iterator == nullptr) {
		return;
	} else {
		iterator =  iterator->m_next;
	}
}

void Iterator::prev() {
	if (iterator == nullptr) {
                return;
	} else {
		iterator =  iterator->m_prev;
	}
}

Iterator& Iterator::operator++() {
	next(); return *this;
}

Iterator Iterator::operator++ (int) {
	auto tmp(*this);
	operator++();
	return tmp;
}

Iterator& Iterator::operator-- () {
	prev(); 
	return *this;
}

Iterator Iterator::operator-- (int) {
	auto tmp (*this);
	operator-- ();
	return tmp;
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
