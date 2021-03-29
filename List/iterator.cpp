#include "node.h"
#include "iterator.h"


Iterator::void next() {
	if (iterator == nullptr) {
		return;
	} else {
		iterator =  iterator->next;
	}
}

Iterator::void prev() {
	if (iterator == nullptr) {
                return;
	} else {
		iterator =  iterator->prev;
	}
}

Iterator::Iterator()
	:iterator (nullptr) {}

Iterator::Iterator (Node* node)
	:iterator (node) {}

Iterator::Iterator (const Iterator& itr)
	:iterator(itr.iterator) {}

Iterator::Iterator& operator++() {
	next(); return *this;
}

Iterator::Iterator operator++(int) {
	auto tmp(*this);
	operator++();
	return tmp;
}

Iterator::Iterator& operator--() {
	prev(); 
	return *this;
}

Iterator::Iterator operator--(int) {
	auto tmp(*this);
	operator--();
	return tmp;
} 

Iterator::bool operator==(const Iterator& itr) {
	return iterator == itr.iterator;
} 

Iterator::bool operator!=(const Iterator& itr) {
	return iterator != itr.iterator;
} 

Iterator::int& operator*() {
	return iterator->data;
}

Iterator::Iterator& operator->() {
	return *this;
}
