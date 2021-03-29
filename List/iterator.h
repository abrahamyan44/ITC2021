#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

class Iterator
{
    public:
        Node* iterator;
        void next();
		void prev();

		Iterator();
		Iterator (Node* node);
		Iterator (const Iterator& itr);
        Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
		bool operator==(const Iterator& itr);
		bool operator!=(const Iterator& itr);
		int& operator*();
		Iterator& operator->();

};
          
#endif
