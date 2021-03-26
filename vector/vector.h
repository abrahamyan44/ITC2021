
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
template <class T>

class Vector {

private:
	T* arr;
	int size;
	int capacity;

public:
	Vector();//default constructor
	Vector(const int& size, const T& val);//fill constructor
	int getsize()const;
	int getcapacity()const;
	void pushback(const T& value);
	void popback();
	~Vector();//destructor
	Vector( Vector<T>& vector1);//copy constructor 
	void operator=( Vector<T>& vector1);//assignement operator
	T operator[](const int& index);//returns element with index
	void print();
	bool empty();
	void reserve(const int& res_size);
    void shrink_to_fit();
    void insert(const T& value, const int& index);//add element at pos
};

template class Vector<int>;
template class Vector<char>;
#endif

