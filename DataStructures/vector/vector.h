#pragma once

template <class T>
class vector {
    int capacity, size;
    static const int surplus = 100;
    T* arr;
public:
    vector();
    vector(const int size);
    vector(const vector& a);
    vector& operator=(const vector& a);
    void push_back(const T d);
    void pop_back();
    bool empty() const;
    int get_size() const;
    int get_capacity() const;
    void create_new_array(const int cap);
    void shrink_to_fit();
    T& operator[](int index);
    ~vector();
};