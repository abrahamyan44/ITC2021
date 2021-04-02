#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

class Iterator
{
private:
    void Next();
    void Prev();
public:
    Node* iterator;
	Iterator();
	Iterator (Node* node);
	Iterator (const Iterator& itr);
    Iterator& operator++();
	Iterator operator++ (int);
	Iterator& operator--();
	Iterator operator-- (int);
	bool operator== (const Iterator& itr);
	bool operator!= (const Iterator& itr);
	int& operator*();
	Iterator& operator->();

};
          
#endif
