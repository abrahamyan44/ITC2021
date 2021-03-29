#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>
#include "node.h"
#include "iterator.h"

class List
{
    private:
        Node* head;
        Node* tail;
    public:
        int size() const;
        void insert (int pos, const int& value);
        void erase (int pos);
        void push_back(const int& value);
        void push_front(const int& value);
        int top_back();
        int top_front();
        void pop_back();
        void pop_front();
        Iterator begin();
        Iterator end();
    public:
        List();
        List(int count, int value);
        List(const List& ll);
        ~List();
        List& operator=(const List& ll);
        friend std::ostream& operator<<(std::ostream& out, const List& ll);
};

#endif
