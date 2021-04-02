#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>
#include "node.h"
#include "iterator.h"

class List
{
private:
    Node* m_head;
    Node* m_tail;
public:
    int Size() const;
    void Insert (int position, const int& value);
    void Erase (int position);
    void PushBack (const int& value);
    void PushFront (const int& value);
    int TopBack();
    int TopFront();
    void PopBack();
    void PopFront();
    Iterator Begin();
    Iterator End();
    List();
    List (int count, int value);
    List (const List& ll);
    ~List();
    List& operator= (const List& ll);
    friend std::ostream& operator<< (std::ostream& out, const List& ll);
};

#endif
