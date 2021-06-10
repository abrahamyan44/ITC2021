#pragma once
#include <iostream>

template <class T>
class list {
    struct node {
        T data;
        node* next;
        node* prev;
        node(T d) {
            next = prev = nullptr;
            data = d;
        }
    };
    node* first;
    int size;

public:
    list();
    list(const list& a);
    void push_back(T d);
    void push_front(T d);
    void pop_back();
    void pop_front();
    void insert(int index, T d);
    void remove(int index);
    list& operator=(const list& a);
    bool operator==(const list& a) const;
    bool operator!=(const list& a) const;
    bool empty() const;
    int get_size() const;
    void print() const;
    ~list();

    class iterator {
        node* cur_node;
    public:
        iterator() 
            :cur_node(first) {}

        iterator(node* a)
            :cur_node(a) {}

        iterator& operator=(const node* a) {
            cur_node = a;
            return *this;
        }

        iterator& operator++() {
            if(cur_node) {
                cur_node = cur_node->next;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator it = *this;
            ++*this;
            return it;
        }

        iterator& operator--(int) {
            if(cur_node) {
                cur_node = cur_node->prev;
            }
            return *this;
        }

        iterator operator--() {
            iterator it = *this;
            --*this;
            return it;
        }

        bool operator!=(const iterator& it) {
            return cur_node != it.cur_node;
        }

        bool operator==(const iterator& it) {
            return cur_node == it.cur_node;
        }

        T operator*() {
            return cur_node->data;
        }
    };

        
    iterator begin() {
        return iterator(first);
    }

    iterator end() {
        return iterator(nullptr);
    }
};