#include <cassert>
#include <iostream>
#include "vector.h"

template <class T>
void vector<T>::create_new_array(const int cap) {
    if(capacity > 0)
        delete[] arr;
    capacity = cap;
    arr = new T[cap];
    for(int i = 0; i < cap; ++i) {
        arr[i] = 0;
    }
}

template <class T>
vector<T>::vector() 
    :size(0), capacity(0) {
        create_new_array(surplus);
}

template <class T>
vector<T>::vector(const int size) 
    :capacity(0), size(size) {
    create_new_array(size + surplus);
}

template <class T>
vector<T>::vector(const vector& a) 
    :size(0), capacity(0) {
    *this = a;
}

template <class T>
vector<T>& vector<T>::operator=(const vector& a) {
    if(this == &a) {
        return *this;
    }
    size = a.size;
    if(capacity < a.capacity) {
        create_new_array(a.capacity);
    }
    for(int i = 0; i < capacity; ++i) {
        if(i < size) {
            arr[i] = a.arr[i];
        }
    }

    return *this;
}

template <class T>
void vector<T>::push_back(const T d) {
    if(size == capacity) {
        vector<T> x = *this;
        create_new_array(capacity + surplus);
        *this = x;
    }
    arr[size] = d;
    ++size;
}

template <class T>
void vector<T>::pop_back() {
    if(empty()) {
        return;
    }
    arr[size - 1] = 0;
    --size;
}

template <class T>
bool vector<T>::empty() const {
    return size == 0;
}

template <class T>
int vector<T>::get_size() const {
    return size;
}

template <class T>
int vector<T>::get_capacity() const {
    return capacity;
}

template <class T>
void vector<T>::shrink_to_fit() {
    vector<T> x = *this;
    create_new_array(size);
    for(int i = 0; i < capacity; ++i) {
        arr[i] = x[i];
    }
}

template <class T>
T& vector<T>::operator[](int index) {
    assert(index >= 0 && index < size);
    return arr[index];
}

template <class T>
vector<T>::~vector() {
    size = capacity = 0;
    delete[] arr;
}


int main() {
    vector<int> a;
    for(int i = 0; i < 5; ++i) {
        a.push_back(i);
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    std::cout << a.get_size() << "\n";
    return 0;
}
